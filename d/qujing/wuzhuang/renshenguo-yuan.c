//Cracked by Roath
//renshenguo-yuan.c

inherit ROOM;

void create ()
{
	set ("short", "�˲ι�԰");
	set ("long", @LONG

�ô��һ���˲ι�԰���޴�Ĺ����ϵ���һöö���˴������ε�
�˲ι���ֻ�ǲ�֪����������Ū����������˵���˲ι������ޱȣ�
Ҫ����ժһ��ʲô���Բ��ϡ�
LONG);

	set("exits", 
	([ //sizeof() == 4
	]));
	
	set("objects", 
	([ //sizeof() == 1
		"/d/obj/drug/renshenguo-fake" : 1,
	]));

	set("outdoors", "xy9");
        set("no_net_dead", 1);
        set("no_get", 1);
	set("alternative_die",1);

	setup();
}

