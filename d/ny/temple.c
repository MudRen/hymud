

inherit ROOM;

void create()
{
        set("coor",({50,4750,10}));
	set("short", "������");
        set("long",
"����һ��ʮ���Ͼɵĳ�����������ǰ�������Ϲ�����һ������ĳ��������Ͼɣ�������\n"
"�������ѱ����޹���ںڵ���ɫ����ʾ����ض��൱�ܵ���ͽ�ľ�����ͻȻ�㷢�����ǽ��\n"
"�и���̫���Եİ��ţ�\n"
);
        set("exits", ([ /* sizeof() == 2 */
                "southeast" : __DIR__"work",
                "west" : __DIR__"square",
        ]));
            set("no_fight", 1);
    set("no_spells",1);
    set("no_magic","1"); 
    set("objects", ([ /* sizeof() == 3 */

                __DIR__"npc/keeper" : 1, 
        ]));
        set("valid_startroom", 1);
        set_temp("light",1);
        setup();
}
