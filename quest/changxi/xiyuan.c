// xiyuan.c ����ϷԺ 
// ����lywin 2000/6/22 

#include <ansi.h>
inherit ROOM;

 void create()
{
        set("short", "����ϷԺ");
        set("long", @LONG
����������������Ĵ�ϷԺ����ȫ������Ҳ�кܴ�������������Ϸ
Ժ��֯��Ϸ���ӳ���������ȥ���б��ݣ��ǳ����ܺ�����������������
���´����йع������¡���ask guan about job��
LONG
        );

        set("exits", ([
                "north" : "/d/xiangyang/jiedao",
        ]));
	set("objects", ([
		__DIR__"guanshi" : 1,
	])); 
        set("no_fight",1);
        set("no_beg",1);
        set("no_steal",1);
  set("roomif","$botten#��Ϸ����|��Ϸ���|ȡ����Ϸ:ask guan about job|ask guan about over|ask guan about fail$#");

        setup();
	replace_program(ROOM);
}
