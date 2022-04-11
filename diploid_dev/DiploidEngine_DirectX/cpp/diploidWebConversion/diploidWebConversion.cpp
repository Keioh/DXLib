#include "diploidWebConversion/diploidWebConversion.h"

std::string DiploidWebConversion::toWebCode(DiploidBoxV2 object, int red, int green, int blue)
{
	buffer = "webCode/" + object.GetName() + ".html";

	file.WriteOpen(buffer.c_str());
	
	file.SetLine("<!DOCTYPE html>");
	file.SetLine("<meta charset=\"UFT-8\">");
	file.SetLine("<html>");
	file.SetLine("<head>");

	file.SetLine("<script type=\"text/javascript\" src=\"" + object.GetName() + ".js\"></script>");

	file.SetLine("</head>");

	file.SetLine("<body onLoad=\"" + object.GetName() + "_BOX_OBJ()\">");

	file.SetLine("<canvas id=\"canvas_" + object.GetName() + "\">");

	file.SetLine("</canvas>");
	file.SetLine("</body>");
	file.SetLine("</html>");

	file.Close();


	buffer = "webCode/" + object.GetName() + ".js";

	file.WriteOpen(buffer.c_str());

	file.SetLine("function " + object.GetName() + "_BOX_OBJ(){");

	file.SetLine("var canvas = document.getElementById('canvas_" + object.GetName() + "')");
	file.SetLine("var context = canvas.getContext('2d')");

	file.SetLine("context.fillStyle = 'rgb(" + std::to_string(red) + " ," + std::to_string(green) + " ," + std::to_string(blue) + ")';");
	file.SetLine("context.fillRect(" + std::to_string((int)object.GetPosition().x) + "," + std::to_string((int)object.GetPosition().y) + "," + std::to_string((int)object.GetSize().x) + "," + std::to_string((int)object.GetSize().y) + ")");


	file.SetLine("}");


	file.Close();

	object.GetSize().x;


	return buffer;
}