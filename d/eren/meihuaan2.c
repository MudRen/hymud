 inherit ROOM;
#include <ansi.h> 
void create() 
{
        set("short", "��Ժ");
        set("long", @LONG
����������̦��ʯ�ף�����һ�ƣ��аܵĴ��ž͡�ѽ����һ�����ˣ���������
�������ǵ�̾Ϣ��Ժ�������Ҷ�ܺ񣬺������綼������һ����ͳ����о�����
������磬�����������Ժ�䡣�������ïʢ��÷���֣���ʮ����ǰ��Ѫ��������
���ѱ�����������
LONG
        );
        set("exits", ([ 
                "out": __DIR__"meihuaan",
                "north": __DIR__"meihuaan3",
        ]));
        set("objects", ([
                
        ]) );
        set("coor/x",-1300);
        set("coor/y",2030);
        set("coor/z",100);
        setup();
        replace_program(ROOM);
}      
