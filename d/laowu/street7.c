 inherit ROOM;
void create()
{
        set("short", "���ر���");
        set("long", @LONG
�����µı��ӣ��������Ի�׳�ۡ�����ʮ�ɣ����������������Ӱ��ܽ���������
ɫȴ����ȱ𴦻�Ҫ�Щ��һ�ο���¶�ں����ϣ�����ǿ�ʼ�⽭��ʱ�������ġ�
��֦Ҳ��֪��˭��ƽ�ˣ�����ȴ����һС��¶�ں����⡣
LONG
        );
        set("exits", ([ 
  "northeast" : __DIR__"street3",
]));
        set("outdoors", "laowu"); 
        set("coor/x",21);
        set("coor/y",12040);
        set("coor/z",0);
        setup();
}
void init()
{
        add_action("do_zha", "bomb");
} 
int do_zha()
{
        object me, *inv;
        int i;
        object exp;
        object con,item;
        me = this_player();
        if( !(int)me->query("marks/��ϼ"))
        return 0;
        inv = all_inventory(me);
                       for(i=0; i<sizeof(inv); i++)
                {
                                
                        if( (int) inv[i]->query("explosive") )
                                exp = inv[i];
                }
        if( !exp) 
   {
        tell_object(me,"��û�������Ķ�����\n");
        return 1;
        } 
        message_vision("$N��ȼ�����е�"+exp->name()+"������
ֻ����һ��������죢�䣢�����ӱ�ը�����󶴣�\n", me, exp);
        if(!me->query("m_success/����԰Ͱ"))
        {
                me->set("m_success/����԰Ͱ",1);
                me->add("score",300); 
        }
        destruct(exp);
        con = new(__DIR__"obj/seal");
        item = new(__DIR__"obj/jadepai");
        if( con && item){
        item->move(con);
        con->move(this_object());
        me->set("marks/��ϼ",0);
                        }
        return 1; 
}  
