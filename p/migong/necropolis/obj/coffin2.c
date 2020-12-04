#include <ansi.h>
inherit ITEM; 

int generate_monk;
void set_generate_monk(int i) {
	generate_monk = i;
}
int query_generate_monk() {
	return generate_monk;
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
	object monk;
	
	if(!arg || (arg!="coffin" &&  arg!="�ײ�")) 
		return notify_fail("��Ҫ��ʲô��\n");
		
	if(query_generate_monk()) {
		message_vision("$N�ƿ��˹ײģ���������ʲô��û�С�\n",this_player());
		return 1;
	} else {
		message_vision("$N�ƿ��˹ײģ������Ȼ�и����С�\n",this_player());
		monk = new("/p/migong/necropolis/npc/monk");
		monk->move(environment(this_player()));
		message_vision("$N̾�˿����������Ǳ������ˡ�\n",monk);
		set_generate_monk(1);
		return 1;
	}
}