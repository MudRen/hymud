#include <ansi.h>
inherit NPC;  
void create()
{
        set_name("���", ({ "yang zheng","yang","zheng" }) );
        set("long",
                "һ����������ڡ���������������ʮ��ĺ��ӣ���������ϡ�\n"); 
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
/*
        set("chat_chance", 1);
        set("chat_msg", ({
"�����˫ȭ����ŭ���۾����ƺ���ó���������\n"
}) ); 
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
        carry_object("/d/tieflag/obj/leavehook")->wield();
} 
/* 
int accept_object(object who, object ob)
{
        object hook,sword,me,room;
        
        me=this_object();
        room=environment();
        if(ob->query("name")!=MAG"���"NOR) return 0;
        if(!present("di qinglin",room)) return 0;
        if(who->query_busy()) return 0;
        if(me->query_busy()) return 0;
        
        set_temp("����𹳵���",who);
        hook=new("/d/tieflag/obj/leavehook");
        hook->move(me);
        if(sword=present("sword",me))
        if(sword->query("equipped"))
                command("unwield sword");
        command("wield leave hook");
        return 1;
}
        
*/
void heart_beat()
{
        object me,room,yang;
        int msg;
        
        yang=this_object();
        room=environment(); 
        if(msg=query("dying_msg"))
        {
                me=room->query("���2����");
                if(msg==5)
                   message_vision("$N���������������ĵ�ʬ�壬��û��ע�⵽$n���˽�����\n",yang,me);
                if(msg==4) {
                        message_vision("$N߽����������ġ����ҡ���ʤ�ˡ����Ӵ���Ҳû��˭�������������
�ˣ�����������Ҳ�����ԡ���������\n",yang);
                        if(!me->query("imbue/libie")) {
                                this_object()->imbue_event(me);
                        }
                }
                if(msg==3)
                        message_vision("\n$N��ɫ��ȻתΪƽ����������������𹳣���Ȼ���Լ��Ŀڲ��䣬$n
��ʧɫ������������ֹ��ȴΪʱ����\n",yang,me);
                if(msg==2)
                        message_vision("\n$N��$n΢Ц��������ĳ���ʵ��ʣ��������޺���ֻ��"+RANK_D->query_respect(me)+"�ܽ��ҷ򸾶�
�˺�����Сľ�������������\n",yang,me);
                if(msg==1)
                        {
                                message_vision("$N����Խ��ԽС�������ĵ����������ĵ���ߡ�\n",yang);
                                me->set("libie/���_β��",1);
                                yang->die();
                        }
                add("dying_msg",-1);
        }
        ::heart_beat();
} 
void dying(object me)
{
        set("dying_msg",5);
}   
void die()
{       object me,corpse,*inv,room;
        int i; 
        room=environment();
        if(me=room->query("���2����"))
                me->delete_temp("���_Ŀ�������");
        corpse=new("/d/libie/obj/yangcorpse2");
        corpse->move(room);
        inv=all_inventory(this_object());
        i=sizeof(inv);
        while(i--)
                inv[i]->move(corpse);
   message_vision("�������\n",this_object());
        destruct(this_object());
                
}
void imbue_event(object me){
        object weapon, ob, *inv, obj;
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
                if(!objectp(obj)) {
                        message_vision(HIR"\n�δ�һ����һ��Ѫ������$N���Եĵ��ϡ�\n"NOR, me);
                } else {
                        message_vision(HIR"\n�δ�һ����һ��Ѫ������$N��" + obj->name() + HIR"�ϣ��ֻ������䵽���ϡ�\n"NOR,
                                        me);    
                }
        }else{
                message_vision(HIR"\n�δ�һ����һ��Ѫ������$N��" + weapon->name() + HIR"�ϡ�����\n"NOR,
                                me);
                message_vision(HIR"���է�֣�" + weapon->name() + HIR"������Ŀ���Σ���ת��ͣ�������ֽ�����ȥ��\n"NOR, me);
                if(weapon->query("weapon_prop")) {
                        prop="weapon_prop/";
                }
                if(weapon->query("equipped") == "wielded") {
                        weapon->unequip();
                        message_vision("$N���������ɿ������н��յ�"+weapon->name()+"��\n", me);
           }
                if(me->query("����B/��ɽ_�ճ�") ) {
                        weapon->add(prop+"courage", 5);
                        weapon->add(prop+"flexibility", 5);
                        weapon->add(prop+"agility", 5);
                        weapon->add(prop+"rigidity", 100);
                } else {
                        weapon->add(prop+"courage", 5);
                        weapon->add(prop+"rigidity", 50);
                }               
                weapon->save();
                me->set("imbue/libie", 1);
                me->save();
                return;
        }
        me->set("imbue/libie", 2);
        me->save();
        return;
}     
