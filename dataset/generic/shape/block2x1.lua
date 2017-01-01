local a = 50
local b = a * 2

luaPP =
{
	loadableName = "block2x1",
	points =
	{
		{ 0, 0 },
		{ b, 0 },
		{ b, a },
		{ 0, a }
	},
	customJoints = { },
	origin = { b / 2, a / 2 }
}
