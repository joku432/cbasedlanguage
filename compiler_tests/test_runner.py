import subprocess
import unittest

def compile_and_run(srcfile: str):
    return subprocess.Popen(["..\\build\\lang.exe", srcfile], stdout=subprocess.PIPE).communicate()[0]


class CompilerOutputTests(unittest.TestCase):
    def setUp(self) -> None:
        pass

    def tearDown(self) -> None:
        pass

    def test_output_is_ok(self):
        output = compile_and_run("1")
        with open("result.txt", "r") as f:
            expected_output = f.read()
            self.assertEquals(output, expected_output)


def run_tests() -> None:
    pass



if __name__ == "__main__":
    run_tests()