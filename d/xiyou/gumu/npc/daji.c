//槼�
//��ԯ��Ĺ
 
//daji.c
#include <ansi.h>
inherit NPC;
inherit F_MASTER;
string ask_mieyao();
string ask_cancel(); 
void create()
{
       set_name("槼�", ({"da ji", "daji", "ji"}));
       set("long", "Ů����� ������Ů ����槼�\n");
       set("title", HIB"��Ĺ�Ļ�" NOR);
       set("color", HIW);
       set("gender", "Ů��");
       set("age", 20);
       set("class","yaomo");
       set("attitude", "friendly");
       set("cor", 30);
       set("per", 40);
       set("max_kee", 4500);
       set("max_gin", 800);
       set("max_sen", 4500);
       set("force", 4000);
       set("max_force", 2000);
       set("force_factor", 125);
       set("max_mana", 2000);
       set("mana", 4000);
       set("mana_factor", 100);
    

create_family("��ԯ��Ĺ", 1, "��");
setup();

        carry_object("/d/obj/cloth/tianyi.c")->wear();
        carry_object("/d/obj/weapon/sword/qinghong.c")->wield();
        
}
