//Cracked by Roath
// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
//��������

inherit NPC;
#include "/d/migong/romnpc2.c"
string ask_me();
void create()
{
        set_name("����", ({"fu xing", "xing"}));
   set("title", "��������");
   set("gender", "����");
   set("long", "�����м�һ���ˣ���������ɰ��塣��«�������굤����׭����ǧ���١�
����Ǭ�������ɣ�����������ɾ͡������ĺ������У�ɢ��ʮ���ݸ��С�
����������⣬��ʱ���»����ɡ��������ն��񿡣����Ƴ���Ʈ�ߡ�\n");
        set("attitude", "peaceful");
        set("combat_exp", 12000000);
   create_family("��ׯ��", 2, "����");
   set("age", 70);
   set("per", 100);
        set("str", 30);
        set("int", 30);
        set("cor", 30);
        set("cps", 30);
        set("con", 30);
   set("class", "xian");
   set("rank_info/respect", "�ϸ���");
   set("max_kee", 1000);
   set("max_jing", 1000);
   set("force", 1000);
   set("max_force", 1000);
   set("force_factor", 40);
   set("max_mana", 600);
   set("mana",600);
   set("mana_factor", 50);
   
 

        set("inquiry", ([
     "��ź"     : "��û�����⣬ȥ���������ǰɣ�\n",
                "����"     : "��û�����⣬ȥ������»�ǰɣ�\n",
     "name"     : "�Ϸ�����Ҳ��\n",
     "here"     : "���������ɵ�Ҳ��\n",
     "����"      : "�������¨�ӣ�˭Ҫ�������壡\n",
     "Χ��"     : "��Χ�嶼��֪����\n",

        ]));

   set("time", 1);
   setup();
   initlvl((300+random(300)),8);
   carry_object("/d/obj/cloth/bai")->wear();   
   carry_object("/d/qujing/nanhai/obj/jp2");
}



void die()
{

        if( environment() ) {
        message("sound", "\n\nֻ��һ�����������ǻ���һ���׹�������ֱ���ȥ������\n\n
��������˹���Ц�˼���������\n\n", environment());
        }

        destruct(this_object());
}






