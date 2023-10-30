#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <memory>
using namespace sf;
using namespace std;

class IComponent
{
public:
    virtual ~IComponent() {}
    virtual void Render(RenderWindow &ref) {}
};

class Block2DComponent : public IComponent
{
public:
    Block2DComponent(string filepath, float xPosotion = 1, float yPosotion = 1, float xScale = 1, float yScale = 1, string day = "", string date = "")
    {
        m_texture.loadFromFile(filepath);
        m_sprite.setTexture(m_texture);
        m_sprite.setScale(xScale, yScale);
        m_sprite.setPosition(xPosotion, yPosotion);
    }
    ~Block2DComponent() {}
    void Render(RenderWindow &ref)
    {
        ref.draw(m_sprite);
    }

private:
    Texture m_texture;
    Sprite m_sprite;
};

class DateContainer
{
private:
    string m_name;
    vector<shared_ptr<IComponent>> m_components;

public:
    DateContainer(string name)
    {
        m_name = name;
    }
    ~DateContainer() {}
    void AddDateContainer(string filepath, float xPosotion, float yPosotion, float xScale, float yScale)
    {
        shared_ptr<Block2DComponent> item = make_shared<Block2DComponent>(filepath, xPosotion, yPosotion, xScale, yScale);
        m_components.push_back(item);
    }
    void Render(RenderWindow &ref)
    {
        for (int i = 0; i < m_components.size(); i++)
        {
            m_components[i]->Render(ref);
        }
    }
};

int main()
{
    RenderWindow window(VideoMode(585, 900), "SFML Image Loading");
    float xLogoPosition = 220.0f;
    float yLogoPosition = 20.0f;
    float xIconPrevPosition = 40.0f;
    float yIconPrevPosition = 35.0f;
    // set backgound white for app
    Texture texture;
    texture.loadFromFile("images/bg-main.jpg");
    Sprite bgMain(texture);
    bgMain.setScale(1, 3.0f);
    // set logo
    Font font;
    font.loadFromFile("fonts/Montserrat/Montserrat-ExtraBold.ttf");
    Text logoName("SLC2T", font, 50);
    logoName.setFillColor(Color(186, 15, 46));
    logoName.move(xLogoPosition, yLogoPosition);
    // set icon previous
    Texture icon;
    icon.loadFromFile("images/icon-prev.png");
    Sprite iconPrev(icon);
    iconPrev.setScale(0.2, 0.2);
    iconPrev.setPosition(xIconPrevPosition, yIconPrevPosition);
    // set film'poster
    Texture film;
    film.loadFromFile("images/data/ke-kien-tao.jpg");
    Sprite filmPoster(film);
    filmPoster.setScale(0.3, 0.3);
    filmPoster.setPosition(xIconPrevPosition, 100.0f);
    // set film's name
    Font fontFilmName;
    fontFilmName.loadFromFile("fonts/Montserrat/Montserrat-Bold.ttf");
    Text filmName("Ke Kien Tao", fontFilmName, 30);
    filmName.setFillColor(Color(0, 0, 0));
    filmName.move(xLogoPosition - 15, 100);

    // set font default
    Font fontTitle;
    fontTitle.loadFromFile("fonts/Montserrat/Montserrat-SemiBold.ttf");
    Font fontDesc;
    fontDesc.loadFromFile("fonts/Montserrat/Montserrat-Regular.ttf");
    // set film's category
    Text filmCategory("The loai: ", fontTitle, 18);
    filmCategory.setFillColor(Color(0, 0, 0));
    filmCategory.move(xLogoPosition - 15, 135);
    // set film's category content

    Text filmCategoryDesc("Hanh dong, KHVT,...", fontDesc, 16);
    filmCategoryDesc.setFillColor(Color(0, 0, 0));
    filmCategoryDesc.move(xLogoPosition - 15 + 85, 137);
    // set film's time
    Text filmTime("Thoi luong: ", fontTitle, 18);
    filmTime.setFillColor(Color(0, 0, 0));
    filmTime.move(xLogoPosition - 15, 160);
    // set film's time content
    Text filmTimeDesc("120p", fontDesc, 16);
    filmTimeDesc.setFillColor(Color(0, 0, 0));
    filmTimeDesc.move(xLogoPosition - 15 + 110, 162);
    // set film's language
    Text filmLanguage("Ngon ngu: ", fontTitle, 18);
    filmLanguage.setFillColor(Color(0, 0, 0));
    filmLanguage.move(xLogoPosition - 15, 185);
    // set film's language content
    Text filmLanguageDesc("Tieng Anh - Phu de Tieng Viet", fontDesc, 16);
    filmLanguageDesc.setFillColor(Color(0, 0, 0));
    filmLanguageDesc.move(xLogoPosition - 15 + 105, 187);
    // set film's Rate
    Text filmRate("Danh gia: ", fontTitle, 18);
    filmRate.setFillColor(Color(0, 0, 0));
    filmRate.move(xLogoPosition - 15, 210);
    // set film's Rate content
    Text filmRateDesc("4,6/5", fontDesc, 16);
    filmRateDesc.setFillColor(Color(0, 0, 0));
    filmRateDesc.move(xLogoPosition - 15 + 100, 212);
    // set film's Date
    Text filmDate("Khoi Chieu: ", fontTitle, 18);
    filmDate.setFillColor(Color(0, 0, 0));
    filmDate.move(xLogoPosition - 15, 235);
    // set film's Date content
    Text filmDateDesc("10/11/2023", fontDesc, 16);
    filmDateDesc.setFillColor(Color(0, 0, 0));
    filmDateDesc.move(xLogoPosition - 15 + 110, 237);

    // set film's description heading
    Font fontHeader;
    fontHeader.loadFromFile("fonts/Montserrat-Semibold.ttf");
    Text filmDesc("Mo ta phim", fontHeader, 26);
    filmDesc.setFillColor(Color(0, 0, 0));
    filmDesc.move(xIconPrevPosition, 320);
    // set film's director
    Text filmDirector("Dao dien:", fontTitle, 18);
    filmDirector.setFillColor(Color(0, 0, 0));
    filmDirector.move(xIconPrevPosition, 350);
    // set film's director
    Text filmDirectorName("Huynh Thi Truc Lam", fontDesc, 16);
    filmDirectorName.setFillColor(Color(0, 0, 0));
    filmDirectorName.move(xIconPrevPosition + 100, 352);
    // set film's actor
    Text filmActor("Dien vien long tiêng:", fontTitle, 18);
    filmActor.setFillColor(Color(0, 0, 0));
    filmActor.move(xIconPrevPosition, 375);
    // set film's actor desc
    Text filmActorDesc("Brie Larson, Samuel L. Jackson, Zaw... ", fontDesc, 16);
    filmActorDesc.setFillColor(Color(0, 0, 0));
    filmActorDesc.move(xIconPrevPosition + 200, 377);

    // set bg-action
    Texture bgRed;
    bgRed.loadFromFile("images/bg-red.png");
    Sprite bgAction(bgRed);
    bgAction.setScale(0.3, 0.3);
    bgAction.setPosition(xIconPrevPosition, yIconPrevPosition + 380);
    // set action'title
    Text actionTitle("Chon ngay chieu", fontTitle, 18);
    actionTitle.setFillColor(Color(255, 255, 255));
    actionTitle.move(xIconPrevPosition + 25, yIconPrevPosition + 390);

    // set Date Selection'container

    DateContainer backgroundGraySmall("container");
    for (int i = 0; i < 14; i++)
    {
        if (i < 7)
            backgroundGraySmall.AddDateContainer("images/bg-gray.png", xIconPrevPosition + 72 * i, yIconPrevPosition + 440, 0.16, 0.16);
        else
            backgroundGraySmall.AddDateContainer("images/bg-gray.png", xIconPrevPosition + 72 * (i - 7), yIconPrevPosition + 570 + 200, 0.16, 0.16);
    }
    DateContainer backgroundGrayLarge("container");
    for (int i = 0; i < 4; i++)
    {
        if (i < 2)
            backgroundGrayLarge.AddDateContainer("images/bg-gray.png", xIconPrevPosition + 280 * i, yIconPrevPosition + 570, 0.48, 0.16);
        else
            backgroundGrayLarge.AddDateContainer("images/bg-gray.png", xIconPrevPosition + 280 * (i - 2), yIconPrevPosition + 570 + 70, 0.48, 0.16);
    }
    DateContainer backgroundRed("container");
    for (int i = 0; i < 3; i++)
    {
        if (i == 2)
        {

            backgroundRed.AddDateContainer("images/bg-red.png", xIconPrevPosition, yIconPrevPosition + 380 + i * 130 + 70, 0.3, 0.3);
        }
        else
        {
            backgroundRed.AddDateContainer("images/bg-red.png", xIconPrevPosition, yIconPrevPosition + 380 + i * 130, 0.3, 0.3);
        }
    }
    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
            {
                window.close();
                cout << "Handling event closed" << endl;
                exit(EXIT_SUCCESS);
            }
            if (event.type == Event::KeyPressed)
            {
                cout << "A key was pressedd" << endl;
                if (event.key.code == Keyboard::W)
                {
                    cout << " \t specifically the w key" << endl;
                }
            }
            if (event.type == Event::MouseButtonPressed)
            {
                cout << "Mouse button pressed" << endl;
            }
        }

        window.clear();
        window.draw(bgMain);
        window.draw(iconPrev);
        window.draw(logoName);
        window.draw(filmPoster);
        window.draw(filmName);
        window.draw(filmCategory);
        window.draw(filmCategoryDesc);
        window.draw(filmTime);
        window.draw(filmTimeDesc);
        window.draw(filmLanguage);
        window.draw(filmLanguageDesc);
        window.draw(filmRate);
        window.draw(filmRateDesc);
        window.draw(filmDate);
        window.draw(filmDateDesc);
        window.draw(filmDateDesc);
        window.draw(filmDesc);
        window.draw(filmDirector);
        window.draw(filmDirectorName);
        window.draw(filmActor);
        window.draw(filmActorDesc);
        window.draw(bgAction);
        window.draw(actionTitle);

        backgroundGrayLarge.Render(window);
        backgroundGraySmall.Render(window);
        backgroundRed.Render(window);
        window.display();
    }

    return 0;
}