// Room: /d/snow/weapon_storage.c
inherit ROOM;

void create()
{
        set("short", "���䳡");
        set("long", @LONG
����һ�����ʵı���̨,�������ӭ����չ�������৵�����,
 ������һ����ս�ĳ嶯.��ÿ����˵����棬��վ���Ŵ�����ݵ�
 ��ʿ.............
��ʱ���鲻�Ծ����������ϵ�������Ҳ�������һ������������!
LONG);
        set("exits", ([
                "south" : __DIR__"weapon_storage",
        ]));
	set("no_dead",1);
        setup();
      //  call_other( "/obj/board/biwuchang", "???" );
}
