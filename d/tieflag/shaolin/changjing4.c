 // TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        object ob1,ob2,con;
        set("short", "�ؾ���");
        set("long", @LONG
�ؾ�¥���������ÿ����Ʒ����ϡ��֮�����������㻹ֻ���Լӻ�
����������Ƕ��ֵ��ӣ����ѽ��룬һ������Ѫ�����˵�����ʦ��ʱ��
ʮ��������Ѫд�ɣ����м������ı�Ҷ�������Ե��̱�Ҷ���ɣ�ǧ�겻
�䣬��ϧ��ʶ���ģ��ѽ����⡣
LONG
        );
        set("exits", ([ 
                "down" : __DIR__"changjing3",
        ]));
        set("coor/x",-210);
        set("coor/y",230);
        set("coor/z",80);
        setup();
        con = new(__DIR__"obj/he");
        ob1 = new(__DIR__"obj/beiye");
        ob2 = new(__DIR__"obj/xuejing");
        if(con && ob1 && ob2)
        {
                ob1->move(con); 
                ob2->move(con); 
                con->move(this_object());
        }
}
void init()
{
        add_action("do_get","get");
        if(userp(this_player())) call_out("stealing",5+random(10),this_player());
} 
int do_get(string arg)
{
        string what;
        object me;
        me = this_player();
   if(!userp(me)) return 0;
        if(!arg) return 0;
        if(sscanf(arg,"%s",what) !=1) return 0;
        if(what== "all" || what== "jingshuhe" )
        {
        message_vision("$N���˿����������ˣ�����Ѿ��鴧�뻳�У�����һ�뵽
        �ᱻ����׷ɱ���ľ���������������\n",me);
        return 1;
        }
} 
int stealing(object me)
{
        object ob;
        if(environment(me) == this_object() && !present("mysterious figure",this_object()))
        {
                ob = new(__DIR__"npc/master_17_7");
                message_vision("һ��΢��Ӵ��ⴵ����$N���۾�����գ��һ�¡�����\n",me);
                if(ob) ob->move(this_object());
        }
        return 1;
}     
