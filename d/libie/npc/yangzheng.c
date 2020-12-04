#include <ansi.h>
inherit NPC;  
void create()
{
        set_name("���", ({ "yang zheng","yang","zheng" }) );
        set("long",
                "һ����������ڡ���������������ʮ��ĺ��ӡ�\n"); 
        set("attitude", "friendly");
        set("age",32);
        set("str", 80);
        set("cor",70);
        set("agi",50); 
        set("con",70);
        set("title", HIW"��ͷ"NOR); 
        set("combat_exp", 4000000+random(1000000));
        set("max_neili",3000);
        set("force",3000);
         
    set_skill("leg", 380);             // �����ڹ�
    set_skill("force", 280);             // �����ڹ�
    set_skill("bibo-shengong", 380);     // �̲���
    set_skill("claw", 200);              // ����צ��
    set_skill("hand", 320);              // �����ַ�
    set_skill("finger", 320);            // ����ָ��
    set_skill("tanzhi-shentong", 380);   // ��ָ��ͨ
    set_skill("unarmed", 280);           // ����ȭ��
    set_skill("strike", 280);            // ����ȭ��
    set_skill("luoying-zhang", 380);     // ��Ӣ����
    set_skill("xuanfeng-leg", 380);      // ����ɨҶ��
    set_skill("dodge", 280);             // ��������
    set_skill("anying-fuxiang", 380);    // ��Ӱ����
    set_skill("parry", 200);             // �����м�
    set_skill("sword", 320);             // ��������
    set_skill("luoying-shenjian", 380);  // ��Ӣ��
    set_skill("yuxiao-jian", 380);       // ���｣��
    set_skill("lanhua-shou", 380);       // ������Ѩ��
    set_skill("qimen-wuxing",380);       // ��������
    set_skill("count",380);              // ��������
    set_skill("literate",380);           // ����ʶ��
	  set_skill("chixin-jian", 380);             // �����ڹ�
    set_skill("canglang-bian", 380);             // �����ڹ�
    set_skill("whip", 380);             // �����ڹ�
    map_skill("strike"  , "luoying-zhang");
    map_skill("force"  , "bibo-shengong");
    map_skill("finger" , "tanzhi-shentong");
    map_skill("whip"   , "canglang-bian");
    map_skill("hand"   , "lanhua-shou");
    map_skill("unarmed", "xuanfeng-leg");
    map_skill("leg" , "xuanfeng-leg");
    map_skill("dodge"  , "anying-fuxiang");
    map_skill("sword"  , "chixin-jian");
    map_skill("parry"  , "luoying-zhang");    	

if (random(3)==0)
{
    	prepare_skill("strike", "luoying-zhang");
	prepare_skill("leg", "xuanfeng-leg");
}
else
{
	prepare_skill("finger", "tanzhi-shentong");
	prepare_skill("hand", "lanhua-shou");	
}
        set("chat_chance_combat", 99);
        set("chat_msg_combat", ({
                (: exert_function, "play" :),
                (: exert_function, "qimenzhen" :),
                (: exert_function, "roar" :),
                (: perform_action, "dodge.taohaimangmang" :),
                (: perform_action, "hand.fuxue" :),
                (: perform_action, "strike.shenjian" :),                
                (: perform_action, "strike.xuan" :),                
                (: perform_action, "strike.pikong" :),                
                (: perform_action, "leg.wuying" :),                
                (: perform_action, "leg.kuangfeng" :),                
                (: perform_action, "finger.huayu" :),                
                (: perform_action, "finger.jinglei" :),                
                (: perform_action, "finger.lingxi" :),                
		(: command("unwield yuxiao") :),
		(: command("wield yuxiao") :),
		(: command("unwield bian") :),
(: command("wield bian") :),
(: perform_action, "finger.ding" :), 
	(: perform_action, "finger.zhuan" :), 
(: perform_action, "sword.muyu" :),                
	(: perform_action, "sword.nosword" :),                
		(: perform_action, "sword.trhy" :),                
		(: perform_action, "whip.duoming" :),                
		(: perform_action, "whip.lang" :),                
		(: perform_action, "whip.tlyj" :),                
		(: perform_action, "whip.yljx" :),                									
 
        }));
        set("chat_chance", 1);
        set("chat_msg", ({
"�����˫ȭ����ŭ���۾����ƺ���ó���������\n"
}) );
/*
        set("inquiry", ([
                "���ڰ�" : (: answer_robery :),
                "robery" : (: answer_robery :),
                "���" : (: answer_yang :),
                "yang" : (: answer_yang :),
                "yang zheng" : (: answer_yang :),
                "������" : (: answer_di :),
                "di" : (: answer_di :),
                "di qinglin" : (: answer_di :),
        ])); 
*/
        setup(); 
        carry_object("/clone/misc/cloth")->wear();
        carry_object("/clone/weapon/gangjian")->wield();
}   
int accept_object(object who, object ob)
{
        object hook,sword,me,room;
        
        me=this_object();
        room=environment();
        if(ob->query("name")!=MAG"���"NOR) return 0;
        if(!present("di qinglin",room)) return 0;
//      if(who->query_busy()) return 0;
//      if(me->query_busy()) return 0;
        
        set_temp("����𹳵���",who);
        hook=new("/d/tieflag/obj/leavehook");
        hook->move(me);
        if(sword=present("sword",me))
        if(sword->query("equipped"))
                command("unwield sword");
        command("wield leave hook");
        return 1;
}
          
void heart_beat()
{
        object di,yang,room,hook,ying,who;
        int rival,msg;
        
        ::heart_beat();
        yang=this_object();
        room=environment();
        di=present("di qinglin",room);
        ying=present("ying wuwu",room);
        
        if(query("killed_di"))
        {
           who=ying->query("busy_object");
                call_out("leave_room",3,ying,who);
                delete("killed_di");
        }
        if(msg=query("leaving_msg"))
        {
        if(msg==3)
                message_vision(HIG"$NĬĬ��ȥ����ϵ�Ѫ����ƣ�����������ͻȻ¶����һ˿΢Ц��\n"NOR,yang);
        if(msg==2)
                message_vision(HIG"$N��������������ģ����ӽ��ˣ������ڿ��Իؼ��ˡ���\n"NOR,yang);
        if(msg==1)
                {
                message_vision(HIG"б����Ѫ��$N����ƣ������ӰĬĬ���뿪�����\n\n"NOR,yang);                  
                destruct(yang);
                }
        add("leaving_msg",-1);
        }
        if(rival=query("begin_rival"))
        {
                if(rival==4)
                {
                        command("say ��������ɱ�ģ�");
                        di->set("begin_rival",4);
                }
                else
                {
                        if(rival==3)
                                command("say ʧ�ٵ�����Ҳ�������");
                        if(rival==2)
                                command("hmm");
                        if(rival==1)
                                command("say �Ҿ�֪����һ�����������ģ���Ϊ��̫������̫���ѱ��˷������");
                        di->add("begin_rival",-1);
                } 
        } 
        
        
        if (!query_temp("perform_libie"))
        if (objectp(di))
        if (yang->is_fighting(di))
   if (yang->query_busy())
        if (hook=present("leave hook",yang))
        if (hook->query("equipped"))
        {
                set_temp("perform_libie",1);
                yang->start_call_out( (: call_other, __FILE__, "perform_libie" ,yang,di:), 2);
        }
}
        
void perform_libie(object yang, object di)
{
        message_vision(HIB"\n$Nٿ���۽�������������Ȼ����������\n\n��𹳽������֣������Լ���ۡ�\n"HIR
"\nѪ����\n\n"HIB"$N��۶���\n\n�����бб����ֱ��$n�ʺ�\n\n$n��֮�£����Ѷ�ܲ�����\n
"HIR"Ѫ������\n\n"HIB"$nֱͦͦ�ĵ��䡣����\n"NOR,yang,di);
        yang->start_busy(1);
        di->die();
        delete_temp("perform_libie");
        return;
} 
int do_rival(object di)
{
        if(!objectp(di)) return 0;
        set("begin_rival",4);
        return 1;
} 
void die()
{
        int i;
        object di,ying,room,corpse,*inv;
        object me;
        
        me=this_player();
        room=environment();
        di=present("di qinglin",room);
        di->set("yang_die",1);
        corpse=new("/d/libie/obj/yangcorpse1");
        corpse->move(room);
        inv=all_inventory(this_object());
        i=sizeof(inv);
        while(i--)
                inv[i]->move(corpse);
        
   message("vision",HIR"\n���˫ĿԲ���������ĵĵ�����ȥ������\n"NOR,room);
   message("vision",HIR"�ڵ��µ����һ�̣�����þ�����һ˿������$N�⿪Ѩ����\n"NOR,me);
        destruct(this_object());
} 
void leave_room(object ying,object who)
{       
        object yang,room;
        
        room=environment();
        yang=this_object();
        message_vision(HIW"$N��$n�⿪Ѩ����\n\n"NOR,yang,who);
        who->start_busy(1);
        if (who->query("libie/���_ɱ��������")!=1 
                && who->query("libie/���_ɱ��������")!=2) {
                who->add("score",500);
                who->add("potential",500);
                who->add("combat_exp",20000);
                }
        who->set("libie/���_ɱ��������",2);
        set("leaving_msg",3);
}   
