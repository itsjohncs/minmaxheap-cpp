# Set up the environment
env = Environment(CCFLAGS = ["-Wall", "-Wextra", "-Wno-unused-parameter"])
env.Append(CCFLAGS = ["-I", Dir("gtest/include/").srcnode().path])
env.Append(LIBPATH = ["gtest/"])
env.Append(LIBS = ["pthread", "gtest", "gtest_main"])

sampleTarget = env.Program(target = "test", source = ["test.cpp"])

Default(sampleTarget)

env.Command("doc/", "Doxyfile", "doxygen $SOURCE")

