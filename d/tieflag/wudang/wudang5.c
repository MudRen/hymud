 inherit ROOM;
void create()
{
        object          con, item; 
        set("short", "������");
        set("long", @LONG
����ǽ�Ϲ����䵱��ɽ��ʦ��������Ļ��񡣻�����һ�Ź�̨�ϣ�
����һֻͭ¯����ֻ����ð�����̵Ĺ���������С���������ǽ�Ϲ�
��̫��ȭ������ͼ��ͼ�����Ǳ����ܣ����и�ʽ���У����Խ�Ϊ�ࡣ
�����䵱��������������
LONG
        );
        set("exits", ([ 
                "north" : __DIR__"wudang3",
        ]));
        set("objects", ([
                __DIR__"npc/taoist" : 2,
                __DIR__"obj/wshelf" : 1,
                __DIR__"obj/taiji_book" : 1,
                
        ]));
        set("coor/x",150);
        set("coor/y",-140);
        set("coor/z",50);
        setup();
}  
void reset()
{
        object          *inv;
        object          con, item;
        int             i;
        ::reset();
        con = present("weapon shelf", this_object());
        inv = all_inventory(con);
        if( sizeof(inv) != 1) {
                for(i=sizeof(inv)-1; i>=0; i--) destruct(inv[i]);
                item = new(__DIR__"obj/sword");
                item->move(con);
        }
} 
/*
void init()
{
        add_action("do_get", "get");
} 
int do_get(string arg)
{
        string          obj, from;
        object          me, wall, shelf, table, target, taro; 
        if(sscanf(arg, "%s from %s", obj, from)==2 ) {
                if(obj == "all") {
                        write("һ����̫�ණ����̫���ԡ�\n");
                        return 1;
                }
                table =  present("tong lu",this_object());
                wall =  present("wall",this_object());
                shelf =  present("weapon shelf",this_object());
                target =  present(from,this_object());
                me = this_player();
                if(target == table || target == wall || target == shelf) {
                        taro =  present(obj, target);
                        if(taro && random(10) > 4) {
                                message_vision("$N��û��ע���ʱ�򣬹����������˵�ʲô���Ž����\n", me);
                                me->set_temp("marks/͵��", 1); 
                        }
                }
        }
        return 0;
} 
int valid_leave(object me, string dir)
{
        object *inv, ob;
        int i; 
        if( userp(me) && me->query_temp("marks/͵��")) {
                if( dir == "north"  && ob=present("xie", this_object())) {
                        return notify_fail(ob->name()+"����ȵ����󵨣��������䵱͵������\n");
                }
        } 
        return 1;
}
*/    
