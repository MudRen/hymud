 // TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "������");
        set("long", @LONG
���������ľ��ѳ����������ķ�ȫԴ�����������Ծ������ԣ��徲
��Ϊ��ѧ�ɶ����ڹ��ı�Ҫ��������������ϰ�ڹ����������������°�
�����ģ������������ϧ�ط���С��Զ�����⣬��ϡ���Կ�������
����ۡ԰���ᡣ
LONG
        );
        set("exits", ([ 
  "southeast" : __DIR__"cj",
  "northeast" : __DIR__"banruo",
]));
        set("no_magic", 1);
        set("coor/x",-220);
        set("coor/y",370);
        set("coor/z",70);
        setup();
}
void init()
{
        add_action("do_jump", "��ϰ");
        add_action("do_jump", "dazuo"); 
} 
int do_jump()
{
        object me;
        int wait;
        me = this_player();
        wait = random( 40 - (int)(me->query("con"))) * 2;
        if ( wait <= 20) wait = 21;
        message_vision("$N�����̣�һ���������ڵ��£���\n",me);
        tell_object(me,"��е����������ڻص�������\n");
        remove_call_out("curehimup");
        call_out("curehimup", wait, me);
return 1;
}
void curehimup(object me)
{
        int force;
        force=(int)me->query("max_force");
if( me && environment(me) == this_object())
        {
        message_vision("$N������ȫ�ָ��ˣ���\n", me);
        me->set("neili", force);
        }
return;
}   
