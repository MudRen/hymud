// ROOM:__DIR__"canyon5"

inherit ROOM;
void create()
{
        set("coor",({-300,4200,0}));
	set("short","����С·");
	set("long",
"�ϱ߼�Ϊ���ŹصĹؿڣ���Ƭŵ�������(door)�������ɹ��ڴ򿪿������Խ��룬�����࿴\n"
"ȥ����դ��ӳ������˫������ת�����࣬�����Ļ���һƬ��ͺͺ��ɽ�ڣ����ɵ�ʹ�������\n"
"�뿪����ط���\n"
); // eof(long)
	
	set("exits",([ /* sizeof()==1 */
		"south" : __DIR__"canyon6",	
		"north" : __DIR__"canyon4",
	]) ); //eof(exits)

	set("item_desc", ([
		"door": "��޴�������⼣�߰ߣ��������¿��ϵģ������Ѿ��߸ߵ�̧��\n"
			"����ʧ�����£�����ʲô�������ᱻ�ұ⡣\n",
	]) );	
        set("outdoors","yanmen");
	setup();
	
	replace_program(ROOM);
} //EOF