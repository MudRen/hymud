#include <ansi.h>
inherit NPC;
int give_mail();
void create()
{
        set_name("Ѧ�ɿ�", ({ "xue keke","xue" }) );
        set("nickname",HIY"����"NOR);
        set("gender", "Ů��");
        set("age",19);
        set("class","quest_npc");
        set("npc_difficulty",20);
        set("organization/����","��");
        set("combat_exp", 58000000);
        set("long","��ɫˮ���䣬�·���  �㵭�����������������·���һ����
������Ӱ���ƿ������֣��¹�̸������������ǡ�������������ϡ�
�԰׵Ĺɣ��԰����¡�\n"
        );
        set("max_force",5000);
        set("force",5000);
        set("force_factor",150);
        set("max_kee",200000);
        set("max_gin",32000);
        set("max_sen",32000);
        set("con",40);
        set("int",27);
        set("resistance/kee",99);
        set("resistance/gin",99);
        set("resistance/sen",99);
  set("jing", 20000);
        set("eff_jing", 20000);
        set("max_jing", 20000);        
        set("qi", 22000);
        set("eff_qi", 22000);
        set("max_qi", 22000);
        set("max_jingli", 22000);
        set("neili", 40000);
        set("max_neili", 40000);
        set("max_jingqi",1000);
        set("combat_exp", 9000000);
        set_skill("dodge",300);
        set_skill("cuff",320);
        set_skill("unarmed",300);
        set_skill("parry",300);
        set_skill("blade",380);
         set_skill("feitian-yujianliu",380);
         set_skill("wuxing-dun",380);
        set_skill("shayi",380);
         set_skill("aikido",380);
         set_skill("shayi-xinfa",380);
        set_skill("shiren-jianfa",380);
        set_skill("shiren-quanfa",380);
        set_skill("force",300);
set_skill("huoxinliu-jianfa",380);

        set_skill("literate",250);
        map_skill("blade", "feitian-yujianliu");
        map_skill("force", "shayi-xinfa");
              map_skill("unarmed", "aikido");
        map_skill("dodge", "wuxing-dun");
        map_skill("parry", "shiren-jianfa");
        create_family("����������", 5, "����");
         set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "dodge.break" :),
                (: perform_action, "unarmed.qin" :),
                (: perform_action, "unarmed.niu" :),
                (: perform_action, "unarmed.yaozhan" :),
                (: perform_action, "blade.chaodao" :),
                (: perform_action, "blade.tianxiang" :),
                (: perform_action, "blade.longlianda" :),
                (: perform_action, "blade.suodi" :),
                (: perform_action, "blade.jiu" :),
                (: perform_action, "unarmed.sanchong" :),
        }));
        set("chat_chance", 1);
        set("chat_msg", ({
 "Ѧ�ɿ�����źڰ��Ĳ�񷵭���ص�����̫���������������������Ŵ�ʱ
�˿̣�����һ��С¥�ĵƹ��£���Ҳһ���ڵȴ�����������\n",     }) );  
/*        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                        (:perform_action,"blade.yueshen-feidao":),
        }) ); */
                set("inquiry",([
                        "�":(:give_mail:),
                        ])      );
        setup();
        carry_object(__DIR__"obj/yueshencloth")->wear();
        carry_object(__DIR__"obj/yueshenblade")->wield();
} 
int give_mail()
{               object letter; 
                command("sigh");
                command("say ���±�������������飬��ʱ��ʹ֪�����ԣ�Ҳ������ȥ��");
                if(!this_object()->query("mail_given"))
                {
                        letter=new(__DIR__"obj/zhanshu");
                        message_vision("$N��$n˵����������Ұ�����Ž��������",this_object(),this_player());
                        letter->move(this_player());
                        this_object()->set("mail_given");
                }
                return 1;
} 
object offensive_target(object me)
{
        int sz;
        object *enemy; 
        enemy = me->query_enemy();
        if( !enemy || !arrayp(enemy) ) return 0; 
        sz = sizeof(enemy);
        if( sz > 4 ) sz = 4; 
        if( sz > 0 ) return enemy[random(sz)];
        else return 0;
}
 
