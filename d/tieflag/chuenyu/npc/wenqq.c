// xiaozh.c ���л�
// zly 99.6.22

#include <ansi.h>
inherit NPC;
string ask_yyd();
int ask_me();
void create()
{
        object ob;
        set_name("������", ({ "wen qingqing", "wen", "qingqing"}));
        set("gender", "Ů��");
        set("unique", 1);
        set("age", 20);
        set("long", "
�㽭ʯ���¼�֮Ů����������ɾ���ѩ��˽��Ů��ĸ���ǽ��丧������\n�����೤��ò���绨�����Ŀ��ˣ�����ɰ��������ֹۣ��ĵص�����\n ��Ȼ�������ң����Ǵ���������������޸С�Ҳ���Դ�ˣСƢ����\n");
        set("attitude", "friendly");
        set("shen", 150000);
        set("env/wimpy", 30);
        set("str", 19);
        set("int", 24);
        set("con", 22);
        set("dex", 26);

        set("max_qi", 13000);
        set("qi", 13000);
        set("jing",11600);
          set("max_jing", 11600);
        set("jingli", 12200);
        set("eff_jingli", 12200);        
        set("neili", 24500);
        set("max_neili", 24500);
        set("jiali", 50);

        set("combat_exp", 8500000);
        
        set_skill("force", 180);             // �����ڹ�
        set_skill("huntian-qigong", 180);    // ��������
        set_skill("blade", 380);             // ��������
        set_skill("wuhu-duanmendao", 390);
//      set_skill("fuqi-daofa", 180);        // ���޵���
        set_skill("dodge", 180);             // �����Ṧ
        set_skill("xiaoyaoyou", 180);        // ��ң��
        set_skill("parry", 180);             // �����м�
        
        map_skill("force", "huntian-qigong");
        map_skill("blade", "wuhu-duanmendao");
        map_skill("dodge", "xiaoyaoyou");
        map_skill("parry", "wuhu-duanmendao");

        set("inquiry", ([

"Ӫ��" : (: ask_me :),
        ]));



        setup();

        carry_object("/d/city/obj/necklace")->wear();
        carry_object("/d/city/obj/pink_cloth")->wear();
        carry_object("/d/city/obj/flower_shoe")->wear();



}

/*string ask_yyd()
{
        object me=this_player();
        if(me->query_skill("blade", 1) <120)
                return "���Ȱѵ����Ļ��������˵�ɡ�\n";
        if(me->query("fuqi"))
                return "�ף��㲻���Ѿ�ѧ���˷��޵�������\n";
        if(me->query_temp("mb"))
                return "�ף��Ҳ��ǸղŸ���������\n";
        command("blush");
        return "����޵������ǵ���ʦĸ�����ҵġ�\n";
}
*/
int ask_me()
{
	int i;
        object ob;
	object who = this_player();
	object where = environment(who);
	

	  	if(((int)who->query("jinyong/book13")>=1))
	{
		message_vision("$N��$n˵���� ��������,����˵ʲô����\n",this_object(),who);
		call_out("destroying", 0);     
		return 1;	
	}
	command("thank " + who->query("id"));
	message_vision("$N��$n˵���� лл��������֮������\n",this_object(),who);
	message_vision("$N��$n˵���������ܰ����ҵ��Ҹ��ף�ȥ����ĸ����? �Ҹ�����ѩ���ڱ߳ǵ������ð��¡�\n",this_object(),who);

who->set_temp("book131",1);
	call_out("destroying", 0);                       
	return 1;
}
void destroying()
{   
object ob=this_object();
   message_vision(HIM"$N˵�������������ʧ������......\n"NOR,ob);
destruct(this_object());
   return;      
}