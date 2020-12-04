#include <ansi.h>
//inherit "/d/taiping/npc/smart_npc"; 
inherit NPC;
int show_me(); 
void create()
{
        set_name("��������",({"oldman"}));
        set("long","�����Ѿ���ʮ�����ˣ��������ֱͦ���޷���׺�ϡ���ˣ�¶��������ͻ���
���š�������������������ƣ�ÿһ���������µĺۼ���\n");
        
        set("gender","����");
        set("attitude", "friendly");
        set("group","citizen");
        
        set("combat_exp",4000000);  
        set("age",72);
                
        set("int",40);
        set("cor",40);
        set("cps",40);
        
        set_skill("unarmed",200);
        set_skill("dodge",150);
        set_skill("parry",160);
        set_skill("force",180);
        set_skill("move",200); 
                
        set("max_atman",random(1000));
        set("atman",query("max_atman"));
        set("max_mana",random(500));
        set("mana",query("max_mana"));
        set("max_neili",1000+random(500));
        set("neili",query("max_neili"));
        set("force_factor",100);
        
        set("resistance/kee",random(30));
        set("resistance/gin",random(30));
        set("resistance/sen",random(30));
        
        set("inquiry", ([
                "����" :        (: show_me :),
                "��" :           (: show_me :),
                "�ص�" :         (: show_me :),
        ])); 
//      set("death_msg",CYN"\n$N�ں޵�˵�����ҵĽ��������ǡ������εá���̫������������\n"NOR);          
        set("nb_chat_chance", 100);
        set("nb_chat_msg_combat", ([
                   10: name()+"���������˰���ǿ������Ĺ������\n", 
        ]) );           
        set("chat_chance_combat", 100);
/*        set("chat_msg_combat", ({
             (: auto_smart_fight(20) :),
        }) );*/
        set("chat_chance",1);
        set("chat_msg",({
                name()+"˵�����������������ͺ��ˡ���\n",
        }) );                   
        
//        CHAR_D->setup_char(this_object());
//        auto_npc_setup("wang",200,165,0,"/obj/weapon/","fighter_w","taiji",2);
        
        setup();
        carry_object("/clone/misc/cloth")->wear();    
        add_money("gold", random(3));
}  
void init()
{       
        object ob; 
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
        add_action("do_vendor_list", "list");
} 
void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        if (ob->query_temp("wanma/��ʬ")>=40 && !ob->query("wanma/ƽ��ʬ")) {
                command("touch "+ob->get_id());
                command("say ̫��л�ˣ���ص�Ӧ����̫ƽһ���ˣ�");
                if (!ob->query("wanma/ƽ��ʬ")) {
                        ob->set("wanma/ƽ��ʬ",1);
                        ob->add("combat_exp",1000);
                        ob->add("potential",200);
                        ob->add("wanma/����",1);
                        tell_object(ob,HIW"�㱻�����ˣ�һǧ��ʵս���飬���ٵ�Ǳ�ܣ�\n"NOR);
                   tell_object(ob,HIW"���������ԶС������������ˣ�\n"NOR);
                } 
        }       
        if (ob->query("wanma/ƽ��ʬ")) {
                command("greet "+ob->query("id"));
                return;
        }
        command("say ��λ"+RANK_D->query_respect(ob)+"��ֹ�����ص��й���̫ƽ����");
        return; 
}   
int show_me()   {
        object me,ob;
        
        me=this_player();
        ob=this_object();
        if (me->query("wanma/ƽ��ʬ")) {
                command("say �����İ������������ϵ����ָ���ɨĹ�ˡ�");
                return 1;
        }
        command("say ��ص��԰���ǰ��ʼ�ֹ����������йֽ���������������Ҳ��̫ƽ�ˡ�");
        command("say ���ϵ��˶�����ȥɨĹ��Ҳ�м�������Ľ���ȥ����һȥ��û��������");
        command("shiver");
        command("say ǰЩ���и������·��Ĺ�ү����а���˽�ȥ�����ڻ�û����Ϣ�������׶༪�١�");
        command("say �����ܰ�������Ķ�������ɾ�������ȫ�����ٶ��м�������");
        tell_object(me,"˵�գ����˲�ΡΡ���ߵ�һ�ԡ� \n");
        me->set("wanma/׼��ɱ��ʬ",1);
        return 1;
}     
