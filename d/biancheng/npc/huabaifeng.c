#include <ansi.h>
//inherit "/d/taiping/npc/smart_npc";
inherit NPC;
void create()
{
        set_name("���׷�",({"hua baifeng","hua","baifeng"}));
        set("title",YEL"˫���缦צ���ϸ�"NOR);
        set("long","
���������ź�ɴ����ɫ�ĳ������ư�ɢ���ڵ��ϣ�ֻ¶��һ˫�ɱ񡢲��ϡ�
��צ����֡���˫�ֺ�ʲ���૵��У���ȴ�����������ϲԴ���ร����
�������䡣�������ϲԣ����������ˣ���������ؼ���������\n");
        
        set("gender","Ů��");
                
        set("age",32);          
        set("int",52);
        set("cor",30);
        set("cps",20);
        set("str",40);
        set("per",1);
        
        set_skill("unarmed",200);
        set_skill("dodge",150);
        set_skill("parry",160);
        set_skill("force",180);
        set_skill("move",200); 
        
        set("neili",1500);
        set("max_neili",1500);
        set("force_factor",120);
        set("max_atman",500);
        set("atman",500);
        set("max_mana",500);
        set("mana",500);
        set("combat_exp",1250000);  
        set("attitude", "friendly");
        
        set("resistance/kee",30);
        set("resistance/gin",30);
        set("resistance/sen",30);
        
//      set("death_msg",CYN"\n$N˵�������߲��������߲��ư�����\n"NOR);          
        set("nb_chat_chance", 100);
        set("nb_chat_msg_combat", ([ 
        ]) );           
        set("chat_chance_combat", 100);
//        set("chat_msg_combat", ({
//        (: auto_smart_fight(100) :),
//        }) );
        set("chat_chance",1);
        set("chat_msg",({
//              "�������е���������������˱����Ͳ�ϲ����ܵġ���\n",
        }) );                   
        
//        auto_npc_setup("wang",200,160,0,"/obj/weapon/","fighter_w","fy-sword",2);
        
        setup();
        carry_object("/clone/misc/cloth")->wear();
//      carry_object(__DIR__"obj/gsword")->wield();    
    
} 
void init()
{       
        object me; 
        ::init();
        if( interactive(me = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, me);
        } 
} 
void greeting(object me)
{
        object ob;
        ob=this_object();
        if( !me || environment(me) != environment() ) return;
        if (me->query("wanma/Ѱ�ض�") && !me->query("wanma/ɱ����_ma")) {
                call_out("event1",1,me,0);      
        }
        if (me->query("m_success/������")) return;
        
        if (me->query("wanma/ɱ����_ma")
                && me->query_temp("wanma/ɱ������_ma") && me->query_temp("wanma/ɱ������_ma")
                && me->query_temp("wanma/ɱ�����_ma") && me->query_temp("wanma/ɱ����_ma")
                && me->query_temp("wanma/ɱС����_ma") 
                && !me->query("wanma/׼��ɱͬ��_ma")) {        
                message_vision(CYN"
���׷���˵�ͷ���������������������纮ҹ�еĹ�ޣ������Ⱥ����
��Ⱥ����Ҳ�н��죡��\n"NOR,ob);
                message_vision(CYN"
���׷�˵������һ�������ֵ����Ⱥ��ͬ���ˣ����Ѿ�֪������Ѧ�����
�󾭣���Ҫ�ҳ�����ģ�ɱ�����ǵ�һ�����١���\n"NOR,ob);
                me->set("wanma/׼��ɱͬ��_ma",1);
        }
        if (me->query("wanma/׼��ɱͬ��_ma") 
                && me->query_temp("wanma/�״�_ma") && me->query_temp("wanma/Ѧ��_ma")
                && me->query_temp("wanma/�һ�����_ma") && me->query_temp("wanma/������_ma")
                /*&& me->query_temp("wanma/����_ma") */
                && !me->query("wanma/׼��ɱ����_ma")) {
                message_vision(CYN"
���׷�ת����ȥ�����ں�ɫ������ǰ���૵��û��������������˵ʲô��
Ƭ�̣�����\n"NOR,ob);
                me->set("wanma/׼��ɱ����_ma",1);
        }       
        if (me->query("wanma/׼��ɱ����_ma") && me->query_temp("wanma/ɱ���Ⱥ")
                && me->query_temp("wanma/ɱ������") ){
                
                message_vision("$N��$n�ƿ���Ц�ش󺰣����ڱ��ˡ��������ڱ��ˡ�����\n",this_object(),me);
                message_vision("$Nת����ȥ���ٴι��ں�ɫ������ǰ���૵��û��������������˵ʲô������\n", this_object());
                if(!me->query("wanma/���_ma")){
                                call_out("imbue_event", 2, me);
                        }
                if(!me->query("m_success/������"))
                {
                        me->set("m_success/������",1);
                        me->add("score",500);
                }
            }
        return;
} 
void die()
{
        object me, owner;
        if(objectp(me=query_temp("last_damage_from") ))     
        if(owner=me->query("possessed")) {
                me = owner;
        } 
        me->set_temp("wanma/���׷�_ma",1);
        ::die();
}  
string *event1_msg=     ({
        CYN"
���׷������˵����������ָ���㵽����İɣ��Ҳ������������ʲô��
ֻҪ����Ϊ���ñ�����Ѫ�������������õĴ��ˡ���\n"NOR, 
CYN"Ϊ����һ�죬����׼����ʮ���꣬����ʮ���꣬����ѩ�������ң�Ҷ����
�����ң������Ǳ��������ü�ʮ��������ԩ�꣡������\n"NOR, 
CYN"���������������һ�����ص����ţ��·������������ϵ���������ħ���
�����䡣��\n"NOR, 
CYN"��Ҫ��ס���Ӵ��Ժ�������񣬸��������������ʲô�����ò��ź�
�ڣ���������ô�������ǣ�����Ӧ���ģ���\n"NOR, 
CYN"���������Ҿ����������Ⱥ����̫�죬̫���ף���Ҫ����ȥɱ���������£�
���Ķ���Ů������������������������ζ��\n"NOR, 
});  
void event1(object me, int count)
{
        if (environment(me)!=environment(this_object()) || this_object()->is_fighting()) return;
        tell_object(me,event1_msg[count]+"\n");
        if(++count==sizeof(event1_msg))
        {
                message_vision(CYN"���׷�ͻ�ֻӵ���һ������$N��ǰ�������ϣ�����˵���������ߣ������
�������ǵ�ͷȫ�����������ٻ������ң�����ǵ���Ҫ���㣬��ҲҪ���㣡\n\n\n"NOR,me);
                me->set("wanma/ɱ����_ma",1);
                return;
        }
        else call_out("event1",1,me,count);
        return ;
}     

void imbue_event(object me){
        object weapon, *inv, obj;
        string prop;
   int i;
        if(!interactive(me) || environment(me) != environment(this_object())) {
                return 0;
        }
        obj = me->query_temp("weapon");
        if(objectp(obj) && obj->query("owner")) {
                weapon = me->query_temp("weapon");
        } else { 
                inv = all_inventory(me);        
                for(i=0; i<sizeof(inv); i++) {
                        if(inv[i]->query("weapon_prop") && inv[i]->query("owner")) {
                                weapon = inv[i];
                                break;
                        }
                }       
        }                       
        if(!objectp(weapon)){
                if(!objectp(obj)){
                        message_vision(HIC"\n�������������������ռ䡣����\n"NOR, me);
                } else {
                        message_vision(HIC"\n��������������$N��" + obj->name() + HIC"�ϣ�Ȼ�������ڣ�������\n", me);
                }
        }else {
                message_vision(HIC"\n��������������$N��" + weapon->name() + HIC"�ϣ�һ˲�䣬���˻�Ȼ���򡣡��� \n"NOR,
                                me);
                message_vision(HIC"�����ռ�������ƺ���������" + weapon->name() + HIC"�ϣ���һ���ӾͰ����еİ����ޡ��顢��һ�����ߡ�����\n"NOR, me);
                if(weapon->query("weapon_prop")) {
                        prop="weapon_prop/";
                }
                if(weapon->query("equipped") == "wielded") {
                        weapon->unequip();
             if(random(me->query("����B/̩ɽ_�ճ�")) < 9 ) {
                                weapon->add(prop+"karma", 30);
                                weapon->add(prop+"intelligence", 2);
                                weapon->add(prop+"damage", 5);
                                weapon->add("base_damage", 5);
                        } else {
                weapon->add(prop+"karma", 2);
                                weapon->add(prop+"personality", 30);
                                weapon->add(prop+"damage", 3);
                                weapon->add("base_damage", 3);
                        }
                   weapon->wield();
                } else {
             if(random(me->query("����B/̩ɽ_�ճ�")) < 9 ) {
                weapon->add(prop+"karma", 30);
                                weapon->add(prop+"intelligence", 2);
                                weapon->add(prop+"damage", 5);
                                weapon->add("base_damage", 5);
                        } else {
                weapon->add(prop+"karma", 2);
                                weapon->add(prop+"personality", 30);
                                weapon->add(prop+"damage", 3);
                                weapon->add("base_damage", 3);
                        }
                }
                weapon->save();                 
                me->set("wanma/���_ma", 1);
                me->set_skill("moon-blade", 200);
                me->save();
                return;
        } 
        me->set("wanma/���_ma", 2);
        me->save();
        return;
} 
