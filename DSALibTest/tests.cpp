#include <gtest\gtest.h>
#include <MiscAlgo\stack_queue_algos.h>

class threeStackTest : public testing::Test {
public:
	virtual void SetUp()
	{
		stack.push(0, 0);
		stack.push(1, 1);
		stack.push(2, 2);
		stack.push(0, 10);
	}
	virtual void TearDown(){}
	threeStackTest() : stack(threeStack<int>(2, 2, 2)){}
public:
	threeStack<int> stack;
};


TEST_F(threeStackTest, testPop)
{
	EXPECT_EQ(3, stack.pop(0));
}