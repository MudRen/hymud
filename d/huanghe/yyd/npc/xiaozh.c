// xiaozh.c ���л�
// zly 99.6.22

#include <ansi.h>
inherit NPC;
string ask_yyd();
int ask_me();
void create()
{
        object ob;
        set_name("���л�", ({ "xiao zhonghui", "xiao", "zhonghui"}));
        set("gender", "Ů��");
        set("unique", 1);
        set("age", 20);
        set("long", "
���ǽ�����������͵�Ů��������ò��������ɫ��ɢ����һ�ɲ���Ӣ����\n");
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
            "̫������" : "�����ĸ����˵�꣬�Ѿ�Ц���������ˡ�\n",
            "Ԭ����" : "����ʶԬ��磿Ԭ������������˵�꣬��৵غ���������\n",
            "�����" : "�������Ͼ�Ҫ����ʮ�����ˣ����˺ܶ�Ӣ�����ء�������\n",
"Ӫ��" : (: ask_me :),
        ]));

        set("chat_chance", 3);
        set("chat_msg", ({
            "���лۺ�Ȼ�������Σ�����������������������̨��������״�ɽ��ݡ���\n",
            "���л۵���˵��������������ǵ������ٵ��ˣ�����ʲô�����أ���\n", 
        }) );

        setup();
        if (clonep()) {
                ob = new(__DIR__"obj/yang");
                if (random(4)==0) ob = new("/clone/weapon/gangdao");
                ob->move(this_object());
                ob->wield();
        carry_object(__DIR__"obj/red-cloth")->wear();

}
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
	

	  	if(((int)who->query("jinyong/book14")>=1))
	{
		message_vision("$N��$n˵���� ��������,����˵ʲô����\n",this_object(),who);
		call_out("destroying", 0);     
		return 1;	
	}

	if (who->query("combat_exp",1) < 800000)
	{
	command("look  "+who->query("id"));
	command("sneer "+who->query("id"));
	return notify_fail("ƾ����㱾���������ҵ����£���\n");
	}
	
	command("thank " + who->query("id"));
	message_vision("$N��$n˵���� лл��������֮��������쵶�����ڴ�����\n",this_object(),who);
	message_vision("��˵̫���������ҵĺ����ѣ���������������ˡ����ܰ�����ϵ������?\n",this_object());
        message_vision("̫��������Ƣ���е�֣��ῼ������书��С���ˡ�\n",this_object());
	ob = new(__DIR__"obj/yang");
        ob->move(who);
	i = 200+random(800);
	who->set("jinyong/book14",1);
	who->add("combat_exp",i+8880);
	who->add("potential",i*8);
	who->add("mpgx",10);
	who->add("expmax",2);

	tell_object (who,"��Ӯ����"+chinese_number(i+8880)+"�㾭��"+
	           chinese_number(i*8)+"��Ǳ��"+"ʮ�����ɹ��� ����ɳ����ޣ���\n");
	who->save();
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