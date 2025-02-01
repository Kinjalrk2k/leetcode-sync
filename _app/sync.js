import { config } from "dotenv";
import { LeetCode, Credential } from "leetcode-query";
import { tqdm, TqdmProgress } from "node-console-progress-bar-tqdm";
import ora, { spinners } from "ora";
import * as fs from "fs";
import * as path from "path";
import { fileURLToPath } from "url";

// configure dotenv
config();

/**
 * CONSTANTS
 */
const __dirname = path.dirname(fileURLToPath(import.meta.url));

const sleep = (ms) => new Promise((r) => setTimeout(r, ms));

const tqdmOptions = {
  progressSymbol: "─",
  progressColor: "green",
  maxColWidth: 100,
};

const extConverter = {
  python3: "py",
  python: "py",
  java: "java",
  cpp: "cpp",
  csharp: "cs",
  javascript: "js",
  ruby: "rb",
  swift: "swift",
  golang: "go",
  scala: "sc",
  kotlin: "kt",
  rust: "rs",
  typescript: "ts",
  racket: "rkt",
  erlang: "erl",
  elixir: "ex",
  php: "php",
};

/**
 * Leetcode Query initialize
 */

const credential = new Credential();
await credential.init(process.env.LEETCODE_SESSION); // check .env
const leetcode = new LeetCode(credential);

/**
 * STEP 1
 * Fetching all submissions of the user
 * Note: Only latest submission of each problem is picked up
 */
let stop = false;
let offset = 0;
const limit = 20;

const submissionDetails = [];
const titleSet = new Set();

const spinner = ora("Fetching submissions").start();
while (!stop) {
  const submissions = await leetcode.submissions({ limit, offset });
  offset += limit;

  for (const s of submissions) {
    if (!titleSet.has(s.titleSlug) && s.statusDisplay === "Accepted") {
      titleSet.add(s.titleSlug);
      submissionDetails.push({ title: s.titleSlug, id: s.id, lang: s.lang });
    }
  }

  if (submissions.length == 0) {
    stop = true;
  }

  spinner.suffixText = `[${submissionDetails.length}]`;

  sleep(1000);
}

spinner.stop();
console.log(`${submissionDetails.length} Submissions found!`);

/**
 * STEP 2
 * Fetching the submitted code from leetcode
 */
console.log("Fetching code");
for (let s of tqdm(submissionDetails, tqdmOptions)) {
  const submission = await leetcode.submission(s.id);
  s.code = submission.code;
  s.problem_id = submission.problem_id;
  sleep(1000);
}

/**
 * STEP 3
 * Writing the code in designated directories and files
 */
console.log("Writing code");
for (const s of tqdm(submissionDetails, tqdmOptions)) {
  const ext = extConverter[s.lang];
  const filename = `main.${ext}`;
  const dir = path.join(__dirname, "..", `${s.problem_id || ""}-${s.title}`);
  if (!fs.existsSync(dir)) {
    fs.mkdirSync(dir, { recursive: true });
  }

  const file = path.join(dir, filename);
  fs.writeFileSync(file, s.code);
}
