// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// zhenyuan.c...weiqi, 98.02.24.
// copied a lot of useful functions from "rulai.c"...thanks snowcat:)

#define DEBUG 0

inherit NPC;
inherit F_MASTER;
#include "/d/migong/romnpc2.c"

string expell_me(object me);
string keyword(object me);
string sword_xiaofeng(object me);
string sword_sanqing(object me);
string asked_guo(object me);
string ask_mieyao(object me);
string ask_cancel();

void create()
{
   set_name("��Ԫ����", ({"zhenyuan daxian", "zhenyuan", "daxian"}));
   set("title", "��ׯ�۹���");
   set("gender", "����" );
   set("age", 65);
   set("per", 24);
   set("str", 30);
   set("long", "���α����磬���������С���һλ����֮�棡\n");
   set("class", "xian");
   set("combat_exp", 5600000);
   set("attitude", "peaceful");
   set("taskguai",1);
   create_family("��ׯ��", 1, "��ʦ");
   set("rank_info/respect", "����");
   set_skill("unarmed", 220);
  

   set("max_qi", 4500);
   set("max_jing", 4500);
   set("neili", 5000);
   set("max_neili", 2500);
   set("neili", 7000);
   set("max_neili", 3500);   
   set("force_factor", 200);
   set("mana_factor", 200);

   set("spell_qiankun_on", 1); //to use cast qiankun, must set this.


   set("inquiry", ([
     "name": "�Ϸ���Ԫ��\n",
     "here": "��������ׯ�ۣ�����ס�Ŀɲ��ǵ�ʿ��\n",

   ]) );

   setup();
   initlvl((1380+random(1380)),16);
   carry_object("/d/obj/cloth/xianpao")->wear();
   carry_object("/d/obj/weapon/sword/ruler")->wield();
}





void init()
{
        
     object ob = this_player();
        if( ob->query_temp("kill_tree") )
        {
        command("say С��ë����������ҵ��˲ι����Ȼ����Ϸ򲻿����ˡ�");
        command("slap "+ob->query("id"));
        }

}

