#include <ansi.h> 
 inherit ROOM;
void create()
{
        object          con, item; 
        set("short", "ʯ��");
        set("long", @long
���������˹����죬��ʯ����������Ʋ��ֺ�������ϸ�̡�
ֻ�����ԭ�����õ��嵭���ŵ�������൱���ң��������ƺ���
һ����ҳ��������н���һʯ�������Ϸ���һ��ƣ������ǽ��д
��һ�����ġ��ȡ���
long
        );
        set("exits", ([ 
                //"west" : __DIR__"xzroad2",
                //"east" : __DIR__"xzh1k",
        ]));
        set("item_desc", ([
		"ʯ��" : "�����������һ��ƣ��ƺ������������ȡ�(get wan from table)\n",
		"desk" : "�����������һ��ƣ��ƺ������������ȡ�(get wan from table)\n",
		"����" : "�����������һ��ƣ��ƺ������������ȡ�(get wan from table)\n",
		"��" : "�����������һ��ƣ��ƺ������������ȡ�(get wan from table)\n",
		"table" : "�����������һ��ƣ��ƺ������������ȡ�(get wan from table)\n",
        ]) );  
        set("objects", ([
                __DIR__"obj/table": 1,
        ]));
        set("wan_amount", 10);
	set("coor/x",-430);
        set("coor/y",-250);
        set("coor/z",100);
        setup(); 
        //con = present("table", this_object());
        //if(con && item = new(__DIR__"obj/jiuwan")) item->move(con);

} 
void init()
{
	object ob,con;
	object item;
        add_action("do_throw", "throw");
        if( interactive(ob = this_player()) ) {
                remove_call_out("punish_betray");
                call_out("punish_betray",3, ob);
        }
        con = present("table", this_object());
        if (!living(con)) 
        if (!present("wan",con)) {
                 item = new(__DIR__"obj/jiuwan");
                 item->move(con);
        }

}
void close_path()
{
        if( !query("exits/enter") ) return;
        message("vision",
        "�ź�Ȼ���˹��ϡ�\n",
                this_object() );
                delete("exits/enter");
}  
int do_throw(string arg)
{
        object me,ob;
        me = this_player();
        if( !arg || arg=="" ) return 0; 
        if( arg=="wan" || arg =="����" ) {   //ɾ��arg == "jiuwan"
            if(!ob=present(arg,me) )         // add by xiaolang,���player�����Ƿ��о���,�����ǣ���������û�о���
            	return notify_fail("������û�о��롣\n");
             write("��Ѿ�������������һ�ӡ�\n");
             write("ʯ�ں�Ȼ��ʼ�ƶ���¶����һ�����š�\n");
             if( !query("exits/enter") ) {
                set("exits/enter", __DIR__"alou4");
                call_out("close_path", 10);
                        }
              destruct(ob);    //add by xiaolang  ����о��룬��ô�ݻ���
                return 1;       
        }
                write("��Ҫ��ʲô��\n");
                return 1;
} 
void punish_betray(object ob)
{
        message_vision( BLU"$N��Ȼ����������������й��ر����ζ���������Ѿ���ʼ�е�ģ��������\n"NOR,ob);
        if(!ob->query_condition("green_blood"))
                ob->apply_condition("green_blood",random(10)+10); 
} 

// ����add by xiaolang��û������Ĵ��룬һ��rebootֻ����һ���
void reset()
{
   object *inv;
   object item, con;
   ::reset(); 
   con = present("table", this_object());
   if (!living(con)) 
   if (!present("wan",con)) {
   	item = new(__DIR__"obj/jiuwan");
        item->move(con);
        }
}  