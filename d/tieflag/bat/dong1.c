 inherit ROOM;
#include <ansi.h> 
void create()
{
        set("short", "����");
        set("long", @LONG
����Լ���������˷�ŭ�ľ������������̴ܶ٣�Ȼ��һ���ֹ���ƽ���� 
��ƽ����������ȫ���ڰ�����Ȼ������Ǳ����Σ�գ� �㷢���ұ���һ��
�ţ�rightdoor������Ц�����ź󷢳����ģ�Ц��ͻȻ�����������������
�������������Ķ��ջ󣬼�ֱ�����޷��ܾ������������ƶ�����������һ��
�ţ�leftdoor���������ź�û��������
LONG
        );
        set("objects", ([
        __DIR__"npc/bianfu": 1,
                        ]) );
        set("item_desc", ([
                "rightdoor": "����ȻʲôҲ���������������Ѿ��ӿ���...\n",
                "leftdoor": "���ź��ұ�����һģһ����\n",
        ]) );
        set("coor/x",3310);
        set("coor/y",0);
        set("coor/z",-30);
        setup();
} 
void init()
{
        add_action("do_open", "open");
} 
int do_open(string arg)
{
        int i;
        int damage;
        object me,room;
        if(!arg || arg=="")
        {
                write("��Ҫ��ʲô��\n");
                return 1;
        }
        if( arg == "leftdoor" ) {
           me = this_player();
                message_vision(HIR"$N��һ�ƿ��ţ�һ������Կ�ò����ٿ���ٶ����˳�����\n"NOR,me);
                me->receive_wound("qi",random(1000)+150);
                COMBAT_D->report_status(me,1);
                return 1;
        }
        if( arg == "rightdoor") {
                me = this_player();
                tell_object(me,HIR"���һ�ƿ��ţ�����һ����Ͷ����Ļ������������˹�ȥ�� \n"NOR);
                message("vision",HIR""+me->name()+"��һ�ƿ��ţ�����һ����Ͷ��"+me->name()+"�Ļ�������"+me->name()+"���˹�ȥ�� \n"NOR,environment(me),me);
                room =load_object(__DIR__"room1");
                me->move(room);
                return 1;
          } 
}   
