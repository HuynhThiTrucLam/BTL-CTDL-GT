#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <memory> // tessst
using namespace sf;
using namespace std;
const int SCRWIDTH = 585;
const int SCRHEIGHT = 900;
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
class TextComponent : public IComponent
{
private:
    Text m_text;

public:
    TextComponent(string text, Font &font, unsigned int size, Color color = Color::Black, float xPosotion = 1, float yPosotion = 1)
    {
        m_text.setFont(font);
        m_text.setString(text);
        m_text.setCharacterSize(size);
        m_text.setFillColor(color);
        m_text.setPosition(xPosotion, yPosotion);
    }
    ~TextComponent() {}
    void Render(RenderWindow &ref)
    {
        ref.draw(m_text);
    }
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
class TextContainer
{
private:
    string m_name;
    vector<shared_ptr<IComponent>> m_components;

public:
    TextContainer(string name)
    {
        m_name = name;
    }
    ~TextContainer() {}
    void AddTextContainer(string text, Font &font, unsigned int size, Color color, float xPosotion = 1, float yPosotion = 1)
    {
        shared_ptr<TextComponent> item = make_shared<TextComponent>(text, font, size, color, xPosotion, yPosotion);
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
    RenderWindow window(VideoMode(SCRWIDTH, SCRHEIGHT), "SFML Image Loading");
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
    // center x position
    FloatRect textRect = logoName.getLocalBounds();
    logoName.setOrigin(textRect.width / 2, textRect.height / 2);
    logoName.setPosition(Vector2f(SCRWIDTH / 2.0f, yLogoPosition * 2));
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

    // set font default
    Font fontFilmName;
    fontFilmName.loadFromFile("fonts/Montserrat/Montserrat-Bold.ttf");
    Font fontTitle;
    fontTitle.loadFromFile("fonts/Montserrat/Montserrat-SemiBold.ttf");
    Font fontDesc;
    fontDesc.loadFromFile("fonts/Montserrat/Montserrat-Regular.ttf");
    Font fontHeader;
    fontHeader.loadFromFile("fonts/Montserrat/Montserrat-Semibold.ttf");

    TextContainer textTest("test Text");
    // set film's name
    textTest.AddTextContainer("Ke Kien Tao", fontFilmName, 30, Color::Black, xLogoPosition + 20, 100); // -15
    // set film's category
    textTest.AddTextContainer("The loai:", fontTitle, 18, Color::Black, xLogoPosition - 15, 135);
    // set film's category content
    textTest.AddTextContainer("Hanh dong, KHVT,...", fontDesc, 16, Color::Black, xLogoPosition - 15 + 85, 137);
    // set film's time
    textTest.AddTextContainer("Thoi luong:", fontTitle, 18, Color::Black, xLogoPosition - 15, 160);
    // set film's time content
    textTest.AddTextContainer("120p", fontDesc, 16, Color::Black, xLogoPosition - 15 + 110, 162);
    // set film's language
    textTest.AddTextContainer("Ngon ngu:", fontTitle, 18, Color::Black, xLogoPosition - 15, 185);
    // set film's language content
    textTest.AddTextContainer("Tieng Anh - Phu de Tieng Viet", fontDesc, 16, Color::Black, xLogoPosition - 15 + 105, 187);
    // set film's Rate
    textTest.AddTextContainer("Danh gia:", fontTitle, 18, Color::Black, xLogoPosition - 15, 210);
    // set film's Rate content
    textTest.AddTextContainer("4,6/5", fontDesc, 16, Color::Black, xLogoPosition - 15 + 100, 212);
    // set film's Date
    textTest.AddTextContainer("Khoi Chieu:", fontTitle, 18, Color::Black, xLogoPosition - 15, 235);
    // set film's Date content
    textTest.AddTextContainer("10/11/2023", fontDesc, 16, Color::Black, xLogoPosition - 15 + 110, 237);

    // set film's description heading

    textTest.AddTextContainer("Mo ta phim", fontHeader, 26, Color::Black, xIconPrevPosition, 320);
    // set film's director
    textTest.AddTextContainer("Dao dien:", fontTitle, 18, Color::Black, xIconPrevPosition, 350);
    // set film's director content
    textTest.AddTextContainer("Huynh Thi Truc Lam", fontDesc, 16, Color::Black, xIconPrevPosition + 110, 352);
    // set film's actor
    textTest.AddTextContainer("Dien vien long tieng:", fontTitle, 18, Color::Black, xIconPrevPosition, 375);
    // set film's actor desc
    textTest.AddTextContainer("Brie Larson, Samuel L. Jackson, Zaw... ", fontDesc, 16, Color::Black, xIconPrevPosition + 200, 377);

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

    // text component test
    // TextComponent textTest("heellooo", fontTitle, 40, 100, 100);

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

        window.draw(bgAction);
        window.draw(actionTitle);

        backgroundGrayLarge.Render(window);
        backgroundGraySmall.Render(window);
        backgroundRed.Render(window);
        textTest.Render(window);
        window.display();
    }

    return 0;
}