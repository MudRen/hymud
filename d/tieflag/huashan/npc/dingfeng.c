#include <ansi.h>
inherit NPC;
void goto_batdao(object ob);
void create()
{
    set_name("����", ({ "ding feng", "ding", "feng" }));
    set("long", "
��������������ƮƮ�������������������Ҳ���ú�Ӣ����
���ϸ���Զ������Ц�ݡ�\n" );
 set("nickname", HIC "�����ٷ�"NOR);
 set("gender", "����");
 set("age", 27);
 set("str", 25);
 set("int", 24);
 set("con", 25);
 set("qi", 1000);
 set("max_qi", 1000);
 set("jing", 1000);
 set("max_jing", 1000);
 set("neili", 2500);
 set("max_neili", 1000);
 set("force_factor", 50);
 set("combat_exp", 800000);
 set("attitude", "friendly");
     set("neili", 36400);
        set("max_neili", 36400);
        set("jiali", 50);
        set("max_qi",18200);
        set("max_jing",15200);

        set("combat_exp", 5400000);
        set("shen", 20000);
        set_temp("xunshan", 200);
        set("apprentice_available", 3);

        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "sword.jm" :),
                (: perform_action, "sword.jianzhang" :),
                (: perform_action, "sword.jie" :),
                (: perform_action, "sword.xian" :),                
                (: perform_action, "dodge.huiyanfeiwu" :),                
                (: exert_function, "powerup" :),
        }) );
        
        set_skill("unarmed", 180);
        set_skill("sword", 290);
        set_skill("force", 200);
        set_skill("parry", 200);
        set_skill("dodge", 200);
        set_skill("literate", 200);
        set_skill("huashan-sword", 290);
        set_skill("zixia-shengong", 320);
        set_skill("hunyuan-zhang", 290);
        set_skill("poyu-quan", 290);
        set_skill("feiyan-huixiang", 290);
        set_skill("pixie-sword",280);
        set_skill("zhengqijue",200);

        map_skill("sword", "huashan-sword");
        map_skill("parry", "huashan-sword");
        map_skill("force", "zixia-shengong");
        map_skill("unarmed", "huashan-ken");
        map_skill("dodge", "feiyan-huixiang");
        
         set("chat_chance", 1);
 set("chat_msg", ({
"�����૵�����ɽ����һ�ס����ʮ��ʽ����ȷ�����������������ܼ���
�����صġ��������ʽ�����������硣\n ",
"����΢Ц���������ʮ��ʽ��������ڡ��嵭������,���������ǣ��������ޣ�
��ʵ���飬�Ʊ�δ�� ��\n",
 }) );
 set("inquiry",([
  "���ʮ��ʽ" : "�����˻�ɽ��ɽ֮��������ȴʧ���ˣ�����\n",
 ]) );
 set_skill("unarmed", 70);
   set_skill("move", 100);

        setup();
    carry_object("/clone/misc/cloth")->wear();
    carry_object("/clone/weapon/gangjian")->wield(); 
}    
