#include <ansi.h>
inherit NPC;  
void create()
{
        set_name(HIY"�油"NOR,({"guardian"}));
//      set("title",YEL"���˿�����"NOR);
        set("long", "����һ��ר�Ŵ�����̵�������\n");
        set("age",30+random(20));
        set("attitude", "friendly");
        set("combat_exp", 4500000);
        set("dungeon_npc","eren");
                
        set("max_mana", 1000);
        set("mana", 1000);
        set("max_neili",1000);
        set("neili",1000);
                
        set("cor", 40);
        set("cps", 40);
        set("int",40);
        set("agi",40);
        
        set("chat_chance", 1);
        set("chat_msg", ({
        }) );


        set("force_factor",60);
        setup();
        carry_object(__DIR__"obj/oldcloth")->wear();
        
}  
void init() {
        
   object ob;
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}  
void greeting(object ob) {
        
        if( !ob || environment(ob) != environment() ) return;
        call_out("event1",1,ob,0); 
}  
string *event1_msg=     ({
        CYN"��������˵������֪��������⣬����Ϊ�Ǻ��Ӷ�����\n"NOR,
        CYN"��������˵�������֪�����ĸ�����˭��[������]˾���̵�����������
����İ�������������������¶��Թ��֮ɫ������ȫ��һʮ���ڣ�����
����δ���µĺ��ӣ���������˾���̵Ľ��¡���\n"NOR,
        CYN"��������һָ��Χ�����⼸���ֵܣ�֮�����䵽�ڴ��ʵ���Ҳ�ǰ�˾��
�����͡�\n"NOR,
        CYN"�����������գ�������˹�ʱ��˾�����Ӿ��Ѳ������Һ��Ҳ������С���
���Ҳ������ۣ����������˸����֡�\n"NOR,
        CYN"��������˵������ծ�ӻ����Թ���ˣ����ο����Ӵ�С�ڶ��˹ȳ��󣬶�
��Ŀ妽������׼���֮�£����ס�н���Ѫ�ȳ�ɱ֮�У������䳤����
��һ��˾���̣�����ʹ˳�ȥ����\n"NOR,
        CYN"��������˵�������޿����飬����ִ��Ҫ��ͷ��ֻ����ɱ�ҡ���\n"NOR,
        });  
void event1(object me, int count)
{
        if (environment(me)!=environment(this_object()) || this_object()->is_fighting()) return;
        tell_object(me,event1_msg[count]+"\n");
        if(++count==sizeof(event1_msg))
        {
                message_vision(CYN"������ɱ��"+chinese_number(me->query("MKS"))+"�ˣ��ҵ���Ȼ�����������С���\n"NOR,me);
                return;
        }
        else call_out("event1",1,me,count);
        return ;
}        
