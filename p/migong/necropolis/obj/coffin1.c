#include <ansi.h>
inherit ITEM; 

int generate_taoist;
void set_generate_taoist(int i) {
	generate_taoist = i;
}
int query_generate_taoist() {
	return generate_taoist;
}

void create()
{
        set_name("�ײ�", ({"coffin"}) );
        set_weight(300);
        set("no_get", 1);
        set("unit", "��");
        set("long", "һ�߸���Ĺ�ľ,��������ƿ�����(push)��\n");
        set("value", 2000);
        setup();
} 

void init () {
	add_action("do_push","push");
}

int do_push(string arg) {
        object taoist;
	
	if(!arg || (arg!="coffin" &&  arg!="�ײ�")) 
		return notify_fail("��Ҫ��ʲô��\n");
		
	if(query_generate_taoist()) {
		message_vision("$N�ƿ��˹ײģ���������ʲô��û�С�\n",this_player());
		return 1;
	} else {
		message_vision("$N�ƿ��˹ײģ����������������\n",this_player());
		taoist = new("/p/migong/necropolis/npc/taoist");
		taoist->move(environment(this_player()));
		set_generate_taoist(1);
		return 1;
	}
}