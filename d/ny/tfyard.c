

inherit ROOM;

void create()
{
        set("coor",({-70,4750,10}));
	set("short", "�۾�̨");
	set("long",
"����һ�䲻���ͤԺƽ̨��̨ǰ����С����,������һ��ǧ����������紵��������������\n"
"����Ƣ�Ļ��㡣�ڷ������ֵ���Զ����,��Ȼ����ô���ط���������ͣЪ�ĵط�,һЩ������\n"
"����������,Ʒ��̸��.\n"
);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"mstreet3",
	]));
    set("no_fight", 1);
        set("objects", ([
//               "/d/chaoting/npc/japanese" : 3,  
        ]));

	setup();
	replace_program(ROOM);
}
