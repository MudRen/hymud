 //Created by justdoit at May 2001
//All Rights Reserved ^_^ 
 
inherit ROOM; 
#include <room.h> 
void create() 
{ 
        set("short", "Ǳ��Ȫ");
        set("long", @LONG 
�������У�������ب����һ��Ϫ���������ð��������ǧ����ǰ���Ʊ�Ϊ��ɽ��
ǧ�ض��£���ɽ���٣������ȷḻ�����м�����������˲��ܲ��������ʣ�������
�Ƶ��ĵ���Ͱ��Ƴǵĵ��ӵ�Ҳ������������״�������̵�Ȫˮ����ԡ��ʱ��һ��
���ӷ���������������ʵ���÷Ƿ���
LONG 
           ); 
        set("exits",  
           ([  
       "eastup" : __DIR__"jianlin",
            ])); 
        set("objects",  
           ([  
//           __DIR__"obj/sand" : 1, 
            ])); 
        set("outdoors", "baiyun"); 
        set("no_fly", 1);
        set("coor/x",10); 
        set("coor/y",-1720); 
        set("coor/z",5); 
        setup(); 
//        replace_program(ROOM); 
} 
void init()
{
        add_action("do_wash", "wash"); 
} 
int do_wash()
{
        object me;
        int wait;
        me = this_player();
        me->add_temp("jumpinpool",1);
        wait = random( 5 * (int)me->query_temp("jumpinpool"));
        if ( wait <= 5) wait = 6;
        message_vision("$N���˵�һ����������Ȫ�С�\n",me);
        tell_object(me,"��ů��Ȫˮ����е�����ͨ��������������\n");
        remove_call_out("curehimup");
        call_out("curehimup", wait, me);
return 1;
} 
void curehimup(object me)
{
        int gin,kee,sen;
        if(!me) return;
        gin=(int)me->query("max_jing");
        kee=(int)me->query("max_qi");
        sen=(int)me->query("max_jing");
if( me && environment(me) == this_object())
        {
        message_vision("$N�ľ�����ȫ�ָ��ˣ�����\n", me);
        me->set("eff_jing",gin);
        me->set("eff_qi",kee);
        me->set("eff_jing",sen);
        me->set("jing", gin);
        me->set("qi", kee);
        me->set("jing", sen);
        if(!random(10)) me->delete_temp("jumpinpool");
        }
return ;
} 