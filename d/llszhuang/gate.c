#include <ansi.h>
inherit ROOM;
void create()
{
         set("short", "����ɽׯ����");
        set("long",
"����ɽׯ���ھ������������ǰ����ɽׯ�������Ѿþ����˾�ס����\n"
"ѩ�ѻ������ϣ����ϣ����ϣ����ϣ�������һ��ɱ��͸������ׯǽ�⵽��\n"
"�ǻ�ѩ��һ֧�������������ǽ�ϣ�أ���乵�Ѫ��ѩ�����Ǵ�Ŀ���ĵ�\n"
"Ѫ�֣�\n"+ 
        HIR"                      һ �� �� �� ׯ\n" 
       "                      �� �� �� �� ��\n\n\n"NOR 
);

        set("exits", ([ /* sizeof() == 2 */
          "north" : __DIR__"yongdao1",
          "south" : __DIR__"xueyuan",
        ]));
        set("no_magic", "1");


        setup();
}

