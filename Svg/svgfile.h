/****************************************************************************
 * Copyright (C) 2020 by Vivien DETOURNAY, Florian HILT, Gauthier PICHON    *
 ****************************************************************************/

/**
 * @file svgfile.h
 * @author Vivien
 * @date 07 Nov 2020
 * @brief
 *  Fichier donnée pendant les cours de TP
 *  Fonctions d'affichage du format .svg
 *  (Ajout Gradient,Polygone,Polyline,Ellipse)
 *
 */
#ifndef SVGFILE_H_INCLUDED
#define SVGFILE_H_INCLUDED

#include <string>
#include <fstream>
#include <set>
#include <vector>
#include "Coords.h"

constexpr char defcol[] = "black";

///Classe definissant un gradient, contient une liste de OptionGrad
class Gradient;

///Classe d'un fichier svg
class Svgfile
{
    public:
        Svgfile(std::string _filename = "output.svg", int _width=800, int _height=800);
        ~Svgfile();

        void addDisk(double x, double y, double r, std::string color=defcol);
        void addCircle(double x, double y, double r, double ep, std::string color=defcol);
        void addCircleGradient(double x, double y, double r,Gradient G);
        void addEllipseGradient(double x, double y, double rx, double ry, Gradient G);
        void addEllipse(double x, double y, double rx, double ry, std::string color=defcol);
        void addTriangle(double x1, double y1, double x2, double y2,
                         double x3, double y3, std::string colorFill,
                          double thickness, std::string colorStroke);
        void addTriangle(double x1, double y1, double x2, double y2,
                         double x3, double y3, std::string colorFill=defcol);
        void addRect(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4, std::string colorFill);
        void addPolyline(const std::vector <Coords*>& ListeCoords, std::string colorStroke, double ep);
        void addPolyline(const std::vector <Coords*>& ListeCoords, std::string colorStroke, std::string colorFill, double ep);
        void addPolygone(const std::vector <Coords*>& ListeCoords, std::string colorFill);
        void addPolygoneGradient(const std::vector <Coords*>& ListeCoords, Gradient G);
        void addLine(double x1, double y1, double x2, double y2, std::string color=defcol);
        void addCross(double x, double y, double span, std::string color=defcol);

        void addText(double x, double y, std::string text, std::string color=defcol);
        void addText(double x, double y, double val, std::string color=defcol);
        void addTronc(double x, double y,double coef);

        void addGrid(double span=100.0, bool numbering=true, std::string color="lightgrey");

        static std::string makeRGB(int r, int g, int b);
        void GradientL(int& idg, Gradient G);
        void GradientR(int& idg, Gradient G);

        /// Type non copiable
        Svgfile(const Svgfile&) = delete;
        Svgfile& operator=(const Svgfile&) = delete;

    private:
        std::string m_filename;
        std::ofstream m_ostrm;
        int m_width;
        int m_height;

        // Pour Ã©viter les ouverture multiples
        static std::set<std::string> s_openfiles;
};

///Composée d'un gradient (couleur, opacite, offset)
class OptionGrad
{
    public:
        int m_offset, m_opacity;
        std::string m_couleur;
        OptionGrad(int offset,int opacity,std::string couleur);
};

///Classe definissant un gradient, contient une liste de OptionGrad
class Gradient // Si temps séparé en 2 classe fille+Remplacé dns tt les
{               // fonctions déja implanté
    public:
        std::string m_type;//linear ou radial
        int m_cx,m_cy,m_r,m_fx,m_fy; //si radial
        int m_x1,m_y1,m_x2,m_y2; //si linear
        Gradient(std::string type,int cx,int cy,int r,int fx,int fy, std::vector <OptionGrad*>& ListeGrad);
        ///GRADIENT RADIALE, TYPE="radial"
        Gradient(std::string type,int x1,int y1,int x2,int y2, std::vector <OptionGrad*>& ListeGrad);
        ///GRADIENT LINEAIRE TYPE="linear"
        Gradient();
        std::vector <OptionGrad*> m_ListeGrad;
};

std::string fillBallColor(std::string col);

#endif // SVGFILE_H_INCLUDED



