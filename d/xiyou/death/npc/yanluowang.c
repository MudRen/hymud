//Cracked by Roath
// by happ@ys

#include <ansi.h>

inherit NPC;
//inherit NPC;
inherit F_MASTER;
int send_me();
int work_me();
string expell_me(object me);
string check_book();
int zhua_gui();
string ask_cancel();
string obstacle_sc();

void create()
{
       set_name("������", ({"yanluo wang","wang", "master", "yanluo"}));
       set("long", "��������ۣ�ͷ���ڳ����
������ף��������룬�������������\n");
       set("title", "����ʮ��֮");
        set("class", "youling");
       set("gender", "����");
       set("age", 50);
       set("attitude", "peaceful");
       set("shen_type", 1);
       set("per", 10);
       set("max_kee", 1100);
       set("max_gin", 1100);
       set("max_sen", 1100);
       set("force", 1150);
       set("max_force", 1000);
       set("force_factor", 60);
       set("max_mana", 1500);
       set("mana", 1500);
       set("mana_factor", 50);
       set("combat_exp", 1000000);

      




create_family("���޵ظ�", 2, "���");
setup();

        carry_object("/d/obj/cloth/mangpao")->wear();
        carry_object("/d/obj/weapon/sword/qinghong")->wield();
}
