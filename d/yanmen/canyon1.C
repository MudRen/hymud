// ROOM:__DIR__"canyon1"

inherit ROOM;
void create()
{
        set("coor",({-200,4500,0}));
	set("short","��ʯ����β");
	set("long",
"����Ϊ��ʯ����·�������Ǹ������ƵĻ�ɽ���������������ޱ��޼��գ���ԵΪһɽ�ڣ�\n"
"������һ����ʮ�ߡ����ɵ�����(chain)�������ž����˼���ν�ġ��������ޣ�ѩͤ��\n"
"��\n"
); // eof(long)

	set("item_desc", ([
        	"chain" : @TEXT
    һ��������Եɽ�ڶ��ϣ����޾��ѵ������ͺò�Ҫ��������(climb)��
TEXT
	]) );
	
	set("exits",([ /* sizeof()==1 */
		"southwest" : __DIR__"canyon2",
	]) ); //eof(exits)
	
        set("outdoors","yanmen");
	setup();
	
} 

void init()
{
	add_action("do_climb", "climb");
}

int do_climb(string arg)
{ 
        object me;
        
        me=this_player();
        
	if ( arg != "chain" ) return 0;

        message_vision("$N�ֽŲ��ã�Ŭ������������������Ե��ȥ��\n",me);
                       

	
	if ( ((int)me->query("qi") < 0) ||
	     ((int)me->query("jing") < 0) ||
	     ((int)me->query("neili") < 0) ) {   //�б�ʽ
           	tell_room("/d/xueting/path1",me->name()+"������֧�ˡ�\n");
            	me->move("/d/xueting/path1");
	        return 1;
	}
        
        tell_room("/d/xueting/path1",me->name()+"ƽ���Ĵ���������������\n");
	me->move("/d/xueting/path1");
        return 1;
}
