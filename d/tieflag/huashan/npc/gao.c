#include <ansi.h>
inherit NPC;
void goto_batdao(object ob);
void create()
{
    set_name("������", ({ "gao yanan", "gao" }));
    set("long", "����ĸ�����һ������խ�䣬�Ե�Ӣ������������һ˫���������ӿ���۾���\n" );
        set("title", "��ɽ�� ��ʮ�ߴ�����");
        set("gender", "Ů��");
        set("age", 18);
        set("per", 27);
        set("int", 24);
        set("con", 25);
        set("agi", 23);
        set("class","huashan");
        set("neili", 500);
        set("max_neili", 500);
        set("force_factor", 30);
        set("combat_exp", 800000+random(500000));
        
        set("attitude", "friendly");
        set("chat_chance", 1);
        set("chat_msg", ({
                "�������������������ʦ������������ע������ʲô����\n", 
                "�����е��������������Ϊʲô�ܲ�����Ů�����棿��\n", 
        }) );
        set_skill("unarmed", 75);
        set_skill("move", 80);
        set_skill("dodge", 90);
        set_skill("parry", 80);
        set_skill("force", 80);
        set_skill("sword", 70);
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
        setup();
        carry_object(__DIR__"obj/gcloth")->wear();
        carry_object("/clone/weapon/gangjian")->wield(); 
}     
