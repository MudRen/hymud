//#include <obj.h>
inherit ROOM;
void create()
{
        set("short", "������");
        set("long", @LONG
����һ��ʮ���Ͼɵĳ�����������ǰ�������Ϲ�����һ���
���ĳ��������Ͼɣ������������ѱ����޹���ںڵ���ɫ����
������ض��൱�ܵ���ͽ�ľ�����
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
       //         "south" : __DIR__"eroad1",
                "west" : __DIR__"sstreet1",
        ]));
        set("no_fight", 1);
        set("no_magic", 1);
        set("objects", ([ /* sizeof() == 2 */
              //  OBJ_PAPER_SEAL : 10,
                __DIR__"npc/keeper" : 1,
        ]));
        setup();
        replace_program(ROOM);
}
