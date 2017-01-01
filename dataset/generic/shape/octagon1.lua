require "math"

local a = 50
local b = a / math.sqrt( 2 )

luaPP =
{
	loadableName = "octagon1",
	points =
	{
		{ 0, 0 },
		{ a, 0 },
		{ a + b, b },
		{ a + b, a + b },
		{ a, a + 2 * b },
		{ 0, a + 2 * b },
		{ - b, a + b },
		{ - b, b },
	},
	customJoints = { },
	origin = { a / 2 , a / 2 + b }
}
