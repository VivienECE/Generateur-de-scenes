#include "svgfile.h"
#include <iostream>
#include <sstream>


const std::string svgHeader =
    "<?xml version=\"1.0\" encoding=\"utf-8\"?>\n"
    "<svg xmlns=\"http://www.w3.org/2000/svg\" version=\"1.1\" ";

const std::string svgEnding = "\n\n</svg>\n";

std::set<std::string> Svgfile::s_openfiles;

Svgfile::Svgfile(std::string _filename, int _width, int _height) :
    m_filename{_filename}, m_width{_width}, m_height{_height}
{

    std::cout << "Opening SVG output file : "
              << m_filename << std::endl;

    if ( s_openfiles.count(m_filename) )
        throw std::runtime_error( "File " + m_filename + " already open !" );

    m_ostrm.open(m_filename);
    s_openfiles.insert(m_filename);

    if (!m_ostrm)
    {
        std::cout << "Problem opening " << m_filename << std::endl;
        throw std::runtime_error("Could not open file " + m_filename );
    }

    std::cout << "OK" << std::endl;

    // Writing the header into the SVG file
    m_ostrm << svgHeader;
    m_ostrm << "width=\"" << m_width << "\" height=\"" << m_height << "\">\n\n";
}

Svgfile::~Svgfile()
{
    // Writing the ending into the SVG file
    m_ostrm << svgEnding;

    // Removing this file from the list of open files
    s_openfiles.erase(m_filename);

    // No need to explicitly close the ofstream object (automatic upon destruction)
}

// Helper templated function
template<typename T>
std::string attrib(std::string name, T val)
{
    std::ostringstream oss;
    oss << name << "=\"" << val << "\" ";
    return oss.str();
}

void Svgfile::addDisk(double x, double y, double r, std::string color)
{
    m_ostrm << "<circle "
            << attrib("cx", x)
            << attrib("cy", y)
            << attrib("r",  r)
            << attrib("fill", color )
            << "/>\n";
}

void Svgfile::addCircle(double x, double y, double r, double ep, std::string color)
{
    m_ostrm << "<circle "
            << attrib("cx", x)
            << attrib("cy", y)
            << attrib("r",  r)
            << attrib("fill", "none")
            << attrib("stroke", color )
            << attrib("stroke-width", ep )
            << "/>\n";
}

void Svgfile::addCircleGradient(double x, double y, double r,Gradient G)
{
    m_ostrm <<"  \n\n<defs>\n"
    "    <radialGradient id=\"grad\" cx=\""<< G.m_cx << "%\" cy=\"" << G.m_cy <<"%\" r=\""<< G.m_r  <<"%\" fx=\""<<G.m_fx <<"%\" fy=\""<<G.m_fy  <<"%\">\n";
    for(const auto& i:G.m_ListeGrad)
        m_ostrm <<"      <stop offset=\""<< i->m_offset <<"%\" style=\"stop-color:"<<i->m_couleur<<";stop-opacity:"<<i->m_opacity<<"\" />\n";

    m_ostrm <<"    </radialGradient>\n"
    <<"  </defs>\n"


    << "<circle "
            << attrib("cx", x)
            << attrib("cy", y)
            << attrib("r",  r)
            << attrib("fill", "url(#grad)")
            << "/>\n";
}

void Svgfile::addEllipseGradient(double x, double y, double rx, double ry, Gradient G)
{
    static int i=0; //Variable local à cette fonction
    if (G.m_type=="radial")
        GradientR(i, G);
    else
        GradientL(i, G);

    m_ostrm << "<ellipse "
            << attrib("cx", x)
            << attrib("cy", y)
            << attrib("rx",  rx)
            << attrib("ry",  ry)
            << attrib("fill", "url(#grad"+std::to_string(i)+")")
            << "/>\n";
    i++;
}

void Svgfile::addEllipse(double x, double y, double rx, double ry, std::string color)
{
    m_ostrm << "<ellipse "
        << attrib("cx", x)
        << attrib("cy", y)
        << attrib("rx", rx)
        << attrib("ry", ry)
        << attrib("fill", color )
        << "/>\n";
}
/// <polygon points="200,10 250,190 160,210" style="fill:lime;stroke:purple;stroke-width:1" />
void Svgfile::addTriangle(double x1, double y1, double x2, double y2,
                          double x3, double y3, std::string colorFill,
                          double thickness, std::string colorStroke)
{

    m_ostrm << "<polygon points=\" "
            << x1 << "," << y1 << " "
            << x2 << "," << y2 << " "
            << x3 << "," << y3
            << "\" style=\"fill:" << colorFill
            << ";stroke:" << colorStroke
            << ";stroke-width:" << thickness
            << "\" />\n";
}

void Svgfile::addTriangle(double x1, double y1, double x2, double y2,
                          double x3, double y3, std::string colorFill)
{
    m_ostrm << "<polygon points=\" "
            << x1 << "," << y1 << " "
            << x2 << "," << y2 << " "
            << x3 << "," << y3
            << "\" style=\"fill:" << colorFill
            << "\" />\n";
}

void Svgfile::addRect(double x1, double y1, double x2, double y2,
                          double x3, double y3, double x4, double y4, std::string colorFill)
{
    m_ostrm << "<polygon points=\" "
            << x1 << "," << y1 << " "
            << x2 << "," << y2 << " "
            << x3 << "," << y3 << " "
            << x4 << "," << y4
            << "\" style=\"fill:" << colorFill
            << "\" />\n";
}

void Svgfile::addPolygone(const std::vector <Coords*>& ListeCoords, std::string colorFill)
{
    m_ostrm << "<polygon points=\" ";
    for(const auto& i:ListeCoords)
    {
        m_ostrm << i->getX() << "," << i->getY() << " ";
    }
    m_ostrm  << "\" style=\"fill:" << colorFill
            << "\" />\n";
}

void Svgfile::addPolygoneGradient(const std::vector <Coords*>& ListeCoords, Gradient G)
{
    static int j=10000; //Pour éviter que le static int i nous rattrape
    if (G.m_type=="radial")
        GradientR(j, G);
    else
        GradientL(j, G);

    m_ostrm << "<polygon points=\" ";
    for(const auto& i:ListeCoords)
        m_ostrm << i->getX() << "," << i->getY() << " ";

    m_ostrm  << "\" style=\"fill:" << "url(#grad"+std::to_string(j)+")"
             << "\" />\n";

            j++;
}

void Svgfile::addPolyline(const std::vector <Coords*>& ListeCoords, std::string colorStroke, double ep)
{
    m_ostrm << "<polyline points=\" ";
    for(const auto& i:ListeCoords)
    {
        m_ostrm << i->getX() << "," << i->getY() << " ";
    }
    m_ostrm  << "\" style=\"fill:none;"
            << "stroke:" << colorStroke << ";"
            << "stroke-width:" << ep
            << "\" />\n";
}

void Svgfile::addPolyline(const std::vector <Coords*>& ListeCoords, std::string colorStroke, std::string colorFill, double ep)
{
    m_ostrm << "<polyline points=\" ";
    for(const auto& i:ListeCoords)
    {
        m_ostrm << i->getX() << "," << i->getY() << " ";
    }
    m_ostrm  << "\" style=\"fill:" << colorFill << ";"
            << "stroke:" << colorStroke << ";"
            << "stroke-width:" << ep
            << "\" />\n";
}
void Svgfile::addLine(double x1, double y1, double x2, double y2, std::string color)
{
    m_ostrm << "<line "
            << attrib("x1", x1)
            << attrib("y1", y1)
            << attrib("x2", x2)
            << attrib("y2", y2)
            << attrib("stroke", color)
            << "/>\n";
}

void Svgfile::addCross(double x, double y, double span, std::string color)
{
    addLine(x-span, y-span, x+span, y+span, color);
    addLine(x-span, y+span, x+span, y-span, color);
}

void Svgfile::addText(double x, double y, std::string text, std::string color)
{
    /// <text x="180" y="60">Un texte</text>
    m_ostrm << "<text "
            << attrib("x", x)
            << attrib("y", y)
            << attrib("fill", color)
            << ">" << text << "</text>\n";
}

void Svgfile::addText(double x, double y, double val, std::string color)
{
    std::ostringstream oss;
    oss << val;
    addText(x, y, oss.str(), color);
}

void Svgfile::addGrid(double span, bool numbering, std::string color)
{
    double y=0;
    while (y<=m_height)
    {
        addLine(0, y, m_width, y, color);
        if (numbering)
            addText(5, y-5, y, color);
        y+=span;
    }

    double x=0;
    while (x<=m_width)
    {
        addLine(x, 0, x, m_height, color);
        if (numbering)
            addText(x+5, 15, x, color);
        x+=span;
    }
}

void Svgfile::addTronc(double x, double y,double coef)
{
      //m_ostrm << "<path d=\"M100 250 C 120 230 120 200 120 120 L 140 120 M 140 120 C 140 200 140 230 160 250 L 100 250\" stroke=\"rgb(136,66,29)\" fill=\"rgb(136,66,29)\"/>"; MODEL
      m_ostrm << "<path d=\"M" << x <<" "<< y <<" C "<<x+20*coef<<" "<<y-20*coef<<" "<<x+20*coef<<" "<<" "<< y-50*coef<<" "<<x+20*coef<<" "<< y-130*coef <<" L "<< x+40*coef<<" "<<
      y-130*coef<<" M "<<x+40*coef<<" "<< y-130*coef <<" C "<< x+40*coef<<" "<< y-50*coef <<" "<<x+40*coef <<" "<<y-20*coef <<" "<<x+60*coef<<" "<<y<<" L " <<x<<" "<< y <<
      "\" stroke=\"rgb(136,66,29)\" fill=\"rgb(136,66,29)\"/>";
      //HAUTEUR BASE: 130
      //LARGEUR BASE (SOMMET TRONC):20
}

void Svgfile::GradientR(int& idg, Gradient G)
{
    m_ostrm <<"  \n\n<defs>\n"
    "    <radialGradient id=\"grad" << idg <<"\" cx=\""<< G.m_cx << "%\" cy=\"" << G.m_cy <<"%\" r=\""<< G.m_r  <<"%\" fx=\""<<G.m_fx <<"%\" fy=\""<<G.m_fy  <<"%\">\n";
    for(const auto& i:G.m_ListeGrad)
        m_ostrm <<"      <stop offset=\""<< i->m_offset <<"%\" style=\"stop-color:"<<i->m_couleur<<";stop-opacity:"<<i->m_opacity<<"\" />\n";

    m_ostrm <<"    </radialGradient>\n"
    <<"  </defs>\n";
}

void Svgfile::GradientL(int& idg, Gradient G)
{
    m_ostrm <<"  \n\n<defs>\n"
    "    <linearGradient id=\"grad" << idg <<"\" x1=\""<< G.m_x1 << "%\" y1=\"" << G.m_y1 <<"%\" x2=\""<< G.m_x2  <<"%\" y2=\""<<G.m_y2<<"%\">\n";
    for(const auto& i:G.m_ListeGrad)
        m_ostrm <<"      <stop offset=\""<< i->m_offset <<"%\" style=\"stop-color:"<<i->m_couleur<<";stop-opacity:"<<i->m_opacity<<"\" />\n";

    m_ostrm <<"    </linearGradient>\n"
    <<"  </defs>\n";
}

std::string Svgfile::makeRGB(int r, int g, int b)
{
    std::ostringstream oss;
    oss << "rgb(" << r << "," << g << "," << b << ")";
    return oss.str();
}

Gradient::Gradient(std::string type,int cx,int cy,int r,int fx,int fy, std::vector <OptionGrad*>& Liste): m_type(type),
    m_cx(cx),m_cy(cy),m_r(r),m_fx(fx),m_fy(fy), m_ListeGrad(Liste)
{

}

Gradient::Gradient(std::string type,int x1,int y1,int x2,int y2, std::vector <OptionGrad*>& Liste): m_type(type),
    m_x1(x1),m_y1(y1),m_x2(x2),m_y2(y2), m_ListeGrad(Liste)
{

}

Gradient::Gradient()
{

}

OptionGrad::OptionGrad(int offset, int opacity, std::string couleur) : m_offset(offset), m_opacity(opacity), m_couleur(couleur)
{

}
