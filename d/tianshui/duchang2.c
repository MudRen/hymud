// design by ���ֺ�(find) . all right reserved.

// Room: /u/xiaozhen/duchang2.c

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "�ĳ���¥");
	set("long", @LONG
��������ˮ�ĹݵĶ�¥��ǽ�Ϲ���һ��ľ��(sign)������ר
���ôӾ�Ӫ��͵͵������ľ�үˣǮ�ĵط����������⿪�š���
λ�������ĵĸ��ˡ�������һ��ľ�š�
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "down" : __DIR__"duchang",

]));
        set("item_desc", ([
                "sign" : 
"���ĳ���ֻ���Ŷġ���С��,��������:\n"
"����ɫ�ӵ����ܺͣ�\n"
"       ��   �� ʮ   Ϊ��С����\n"
"       ʮһ �� ʮ�� Ϊ���󡹣�\n"
"       ����ɫ�ӵ�����ͬ�����Сͨ�ԡ�\n"
"������󣬿�С��С����һ��һ��\n"
"���ĳ�ֻ��������Ϊ��ע,һ������Ѻ\n"
"���������Ѻ��ʮ����\n",
        ]));

	
	set("objects",([
	__DIR__"npc/zhao_qixian" : 1,
	__DIR__"npc/judge2" : 1,
]));
	setup();
}

int valid_leave(object who,string arg)
{
	object obj;
	obj = present("zhao qixian",environment(who));
	if(!obj) return 1;
	if(!obj->query("bet_another_id")) return 1;
	if(obj->query("bet_another_id") != who->query("id")) return 1;
	obj->delete("bet_another_name");
	obj->delete("bet_another_id");
	obj->set("money_my",200);
	return 1;
}