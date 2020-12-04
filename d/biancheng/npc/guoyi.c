#include <ansi.h>
#include <command.h> 
//inherit "/d/taiping/npc/smart_npc"; 
inherit NPC;
void create()
{ 
        set_name("����",({"guo yi","guo"}));
        set("title","���ڹײ����");
        set("long", "
һ���׷��Բԣ��ݸɰ�С�İ������ˣ����������˥�����·���ʱ���ᱻ�紵�ߣ�
�ַ·�������Ǳ��紵���ġ������ֵĵط�������һ���ء������˾�վ�ڹײ��\n");
        set("age",67);
        set("combat_exp", 6500000);
        set("attitude", "friendly");     
        set("force_factor",100); 
        set("inquiry", ([
                "Ѫ����" : "Ѫ���ĵ�Ը����һ��Ҫ�������۵ġ�\n\n",
                "parrot" : "Ѫ���ĵ�Ը����һ��Ҫ�������۵ġ�\n\n",
                "*":    "�ǲ�����ˡ�������\n",
        ]));
        set("cor", 40);
        set("cps", 40);
        set("agi",40);
        set("fle",100);
        
        set_skill("unarmed",200);
        set_skill("dodge",150);
        set_skill("parry",160);
        set_skill("force",180);
        set_skill("move",200); 
        
        set("resistance/gin",10);
        set("resistance/kee",50);
        set("resistance/sen",10);
        
        set("chat_chance_combat", 100);
/*        set("chat_msg_combat", ({
                (: auto_smart_fight(60) :),    
        }) );
        
        auto_npc_setup("xuebin",250,180,0,"/obj/weapon/","fighter_w","taiji",2);
*/
        setup();
        carry_object(__DIR__"obj/whitecloth")->wear();
} 
void init() {
        
        object ob;
   ::init();
        add_action("do_answer","answer");
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}  
void greeting(object ob) {
        
        if( !ob || environment(ob) != environment() ) return;
//      if (query("tell_story")) return;
        call_out("bird_story_1",1,ob); 
} 
int bird_story_1(object who)
{
        if (! who->query_temp("parrot/listen_to_story")) {
                tell_object(who,HIR"\n���׿�����һ��˵�����������������ӣ�������Ե�������Ľ�Ұ�أ����Ƿ�Ը����
�ҽ�һ�����£�һ����������һ������Ĺ��£���\n");
                tell_object(who,HIY"���������򡡣���󣯣� \n"NOR);
                who->set_temp("answer_person",1);
        }
        return 1;
} 
int do_answer(string arg)
{
        object skinmask,who;
        who=this_player();
        if(!who->query_temp("answer_person")) return 0;
        if(arg=="yes")
        {
                message_vision(CYN"$N���˵�ͷ��\n"NOR,who);
                call_out("event1",1,who,0);
                set("tell_story",1);
                who->delete_temp("answer_person");
// ��ʱȡ������mark,Ϊ�Ժ����½��������
//                who->set("parrot/listen_to_story",1);
                who->set_temp("parrot/listen_to_story",1);
                return 1;       
        }
        if(arg=="no"){
                message_vision(CYN"$N�޶����Ե�ҡ��ҡͷ��\n"NOR,who);
           message_vision(YEL"����̾�˿������������\n"NOR,who);
                who->delete_temp("answer_person");
                who->set_temp("parrot/listen_to_story",1);
                return 1;
        }
        
        return 0;
}  
string *event1_msg=     ({
        WHT"���׵�������Ҫ���ģ���Ѫ���ĵĹ��¡���\n",
        
        CYN"  ��ʮ����ħʮ���ħѪ���Ż�����ֻѪ���ġ���"+WHT"���˵��������ض�ңԶ��������
���ŵ���"+CYN"����һ�죬��������ħ��������ħ��Ϊ�����ħ�����ٵ����ۻᵽ����Ũ
�μ��ա�������\n"NOR, 
        CYN"  ����Ũ�μ��վ�����ħ�����磬û��ͷ�ϵ����죬Ҳû�н��µĵط���ֻ�з��
�������ͻ��档��\n"NOR, 
        CYN"  ��������ħ��ʮ������ٵ�������ʮ�ؼ����ħ�������ˣ���������ָ�γ���һ
��ħѪ����������ֻѪ���ģ������ǵĺ��񡣡�\n"NOR,
        
        CYN"  ����ֻѪ����ÿ�����궼Ҫ���ٵ��˼�һ�Σ�Ҳ��������Ը������ֻҪ�ܿ�������
���ͻ�����õ�����Ը��������ʲô����Ը�������ܹ�ʵ�֣�"+HIR"������ʵ�֡���\n"NOR, 
        CYN"  ������ǰ�и��˿�������������ʵ��������Ը������\n"NOR, 
        WHT"  �����۾��������˷ܣ��ֳ����ֲ�������������˵�ѡ�\n"NOR, 
        CYN"  ������˾����ҵ��ֵܣ��������������ܹܹ�������\n"NOR, 
        CYN"  ������ǰ���������ϵĸ����������ı������䱦��ɽ��ȴ��һҹ�侹������ʧ��
�ˡ����������Ǹ��������������Ǹ����������ţ���������·�������Ҳ��֪
�Ѳ��˸�ϵ����\n"NOR, 
        CYN"  ��������������������ʾ��׵ģ�˭֪���������ѽ�������ʱ�򣬾�������Ѫ��
�ġ���������һ��Ը��������Ҫ������ʧ�Ե��鱦�һ�������\n"NOR, 
        CYN"  ����ʱ������ҹ������ȻҲ������Ѫ���ĵĴ�˵��ȴ���ǰ��Ű��ɣ�ֻ��������
��һ��ϣ�����ѣ��벻�������ڶ�������������˽������鱦�ͻ����ˡ��ͻ�����
�Ǹ��¹ڳ����������ˡ�������\n"NOR, 
        WHT"  ����Ŀ�к�Ȼ��¶���˿־�֮ɫ����˵������������ʼ������\n"NOR, 
        CYN"  ����˵���������ܵظ��е��й١���˵������׷�������Ĺ��䣬��ҹ�д���һ��
�˵Ļ��ǣ�˵���ı�������һ���ˣ�ȴ�����˹����Ķ����ӹ����ˡ����������ص�
ȥ�ҵ������鱦����Ϊ������˵������仰�������˾ͺ�Ȼ�����ˡ���\n"NOR, 
        CYN"  ����λ�йٸ����˲��ã������˽������˵�ʬ��̧�˻���������ʧ����ˮ������
�ģ����úܿɲ���Ҳ�ܿ��¡���\n"NOR, 
        CYN"  �������ĵڶ���Ը������Ȼ��ϣ���ܾȻ��Լ��Ķ��ӡ���\n"NOR, 
        CYN"  ���������Ͽ�籩�ꡣ��ʱ�����˵Ĺ�ľ��ͣ���������үҲ���Ź��ܹ�����
�ߵĻ����е��ţ������������ڡ�����Ҳ�뿴���������˼����£��ǲ�����Ļ�
������\n"NOR, 
        CYN"  ��ҹ��缱����������Ȼ����һ���ô���������ô�ײĵ����������ţ�����
���ڹײ��д󺰣�Ҫ�˴򿪹ײģ����������������ĺ�������Ȼ���ǹ������ӵ���
�������Ƕ����ó�����\n"NOR, 
        CYN"  ����ү�������������������ˡ�������׼�����ȥ�����Ķ��ӣ���ү����������
ס����������Ҫȥ�������ʵ��̫���أ�̫���¡��������ϡ���ү��谮��һ����
�Ӿͺ�Ȼ�γ��Ѷ̵���һ������������������������ʱ�������еĺ����ô���Ҳ
����ֹͣ�ˡ����������궼����ֹͣ��\n"NOR, 
        CYN"  ������һ��������Ը��Ҳ����ʧ�ˣ����Ķ��ӾͲ��ܸ����������鱦��ȻҲ����
�ٴ�������ʧ����\n"NOR, 
        CYN"  ���������ˣ���������Ҳ���ˣ�ɱ������λ�������������죬�ͷ��˳գ������
�����ǣ�Ҳȫ����ɱл���ү����ʹ���İ��������������鱦�������˸��׳ա���\n"NOR, 
        CYN"  ���������Ѫ���ĵĹ��¡�Ҳ�������ħ��Ҫ����Ѫ����ÿ��������һ���˼��
ԭ����Ϊ��֪�������Ը���������˵ģ���ʱ���������ˣ������ֻ�����\n"NOR,
});  
void event1(object me, int count)
{
        if (environment(me)!=environment(this_object()) || this_object()->is_fighting()) {
                delete("tell_story");
                return;
        }
        tell_object(me,event1_msg[count]+"\n");
        if(++count==sizeof(event1_msg))
        {
                tell_object(me,RED"   ��������ؿ�����һ��˵��Ѫ���ĵ�Ը����һ��Ҫ�������۵ġ�\n\n"NOR,this_object(),me);
                delete("tell_story");
                return;
        }
        else call_out("event1",1,me,count);
        return ;
}        
