// famuchang.c  edit by pian

inherit ROOM;
void create()
{
	set("short", "��ľ��");
	set("long", @LONG
ѩͤ������һ��С���֣�Ҳ��ѩͤ���Է����ķ�ľ��������
�ոտ�����������������ܼ�ª������������﷥ľ��Ȼ��ѩͤ
���ϵĵ�����ȥ���ۣ�����Ǯ����������� famu ���з�ľ����
LONG
        );
	set("exits", ([ /* sizeof() == 1 */
	"west" : __DIR__"palace_path2",
	//"east" : __DIR__"diggroom2",
]));
	setup();
}
void init()
{
        add_action("do_famu", "famu");
}
int do_famu()
{
        object me,ob,*inv;
        int i,s,sk;
        me = this_player();
        sk = 10+random(25);
        sk = sk + sk;
        
        if(me->query("qi")<20)
        	return notify_fail("������������ˣ���������Ϣһ�°ɡ�\n");
        if(me->query("jing")<20)
        	return notify_fail("��ľ��������ˣ���������Ϣһ�°ɡ�\n");
        if(me->is_busy())
        	return notify_fail("������æ��\n");

	// ��ѯover
	
        
        me->start_busy(2);
        message_vision("$N����ɽ������������������ȥ����\n", me);
if (random(12)>= 1)
{
                message_vision("$N�����ֱ۷��飬����$N��ôҲû�п�������\n",me);
        me->receive_damage("qi", 10);
        me->receive_damage("jing", 10);
        me->start_busy(16);
        return 1;        
}         
        // ֱ�Ӽӳ����������ϵͳ����
        i = me->query("kar") + me->query("str") + me->query("int");
        
	
        //5
        if ((sk>50) && (random(sk+i))>((sk+70)*994/1000))
	{
		message_vision("$N�õ�һ�����ľ!!!\n", me);
                me->receive_damage("qi", 10);
        	me->receive_damage("jing", 10);

                ob = new(__DIR__"wood/huanghui_mu");      
                ob->move(me);
                return 1;
        }
        
        //6
        if ((sk>20) && (random(sk+i))>((sk+65)*990/1000))
	{
		message_vision("$N�õ�һ��ѩ��ľ!!!\n", me);
                me->receive_damage("qi", 10);
        	me->receive_damage("jing", 10);

                ob = new(__DIR__"wood/xuesong_mu");      
                ob->move(me);
                return 1;
        }
        
        //7
        if ((random(sk+i))>((sk+65)*9/10))
	{
		message_vision("$N�õ�һ������ľ!!!\n", me);
                me->receive_damage("qi", 10);
	        me->receive_damage("jing", 10);

                ob = new(__DIR__"wood/yangliu_mu");      
                ob->move(me);
                return 1;
        }
        
        message_vision("$N�����ֱ۷��飬����$N��ôҲû�п�������\n",me);
        me->receive_damage("qi", 10);
        me->receive_damage("jing", 10);
  me->start_busy(16);
        return 1;        
}