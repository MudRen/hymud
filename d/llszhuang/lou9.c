#include <ansi.h>
inherit ROOM;
void create()
{
        set("short",CYN"�� �� ¥"NOR);
        set("long",
"���ǽ���¥�ļ�����������ӽ���յĵط���һ����Ѥ�õľ�ս����\n"
"���У�һλ������������ʮ���ħʦ��һλ���ѳ�Ϊ����ĸ��꽣������\n"
"�ľ�ս�Ѿ�ԶԶ����������ʤ�����ﵽ������һ�����档���ǵ������ƶ�\n"
"ʵ��������Ͷ���Ī�������̺�����ؼ��������\n"
);

        set("exits", ([ /* sizeof() == 2 */
          "down": __DIR__"lou8",
        ]));
        set("no_magic", "1");

        set("objects", ([
               __DIR__"npc/kuangren1" : 2,
        ]));

        setup();
}

int valid_leave(object me, string dir)
{
	object obj;
	object fang;
	object who;
	int i;
	who=me;
	if ((dir == "down") &&
	    objectp(present("kuang ren", environment(me))))
	{
		return notify_fail("�и�����ס���㡣\n");
	}
	
  if((int)who->query("jinyong/book12")==4)
{
		i = 1350+random(2000);
		who->set("jinyong/book12",5);
		who->add("combat_exp",i+14000);
		who->add("potential",i*18);
		who->add("mpgx",10);
		who->add("expmax",2);
		tell_object (who,"���ҵ��˺�������ಢӮ����"+chinese_number(i+14000)+"�㾭��"+
		           chinese_number(i*18)+"��Ǳ��"+"ʮ�����ɹ��� ����ɳ����ޣ���\n");
		fang = new("clone/box/item/90");
		fang->move(who);
		who->save();
}
	
        return ::valid_leave(me, dir);
}