// Room: /d/welcome/newbie3
inherit ROOM;

void create ()
{
  set ("short", "����ѵ����");
  set ("long", @LONG
�뿪����֮·����ᵽ����Ϸ�еĵ�һվ��Ҳ����ƽ���ǣ���ƽ��
��������Է��ĵ���Ϥһ�¸���������������ļ�����Ϊ��ƽ��������
���Բ���������Ҳ����������Ŀ�ջ����������ЩǮ��Ҳ���������ѧ��
�������似���ˣ�������ף����̤�뽭���ɣ�
���������Ĵ��ţ�̤����������򽭺��ˡ�����ǵöౣ�����
����(save),����������뿪��(quit),�����ĵط����Կ�(help),ף��
�����졣������12��·�ֱ�ͨ��
yz ���� bj ���� xy ���� dl ���� lz ���� xz ����
qz Ȫ�� wg ��� jp �ձ� cd �ɶ� km ���� xj �½�
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "yz" : "/d/city/kedian",
  "bj" : "/d/beijing/kedian",
  "xy" : "/d/xiangyang/kedian",
  "dl" : "/d/dali/kedian",
  "qz" : "/d/quanzhouchen/kedian",
  "wg" : "/d/wuguan/guanmen",
  "jp" : "/d/japan/dongmen",
  "cd" : "/d/chengdu/kedian",
  "lz" : "/d/lanzhou/kedian",
  "km" : "/d/kunming/kedian",		
  "xz" : "/d/xizang/octostreet",		
  "xj" : "/d/xinjiang/nanmen",	
]));
  set("no_magic", 1);
  set("no_beg",1);
  set("pingan",1);
  set("no_fight", 1);

  setup();
}
int valid_leave(object me, string dir)
{
	object *inv,kicker;
	int sizeinv,n,tt;
	
	if (dir =="pa")
	{
		if ( me->query("PKS") >= 3)
		return notify_fail("��ɱ��̫�����ң�ƽ���ǲ���ӭ�㣡\n");
	
		if ( me->query("age") >= 20)
		return notify_fail("����ô������Ҳ�����ƽ���ǣ�\n");
	
	
		inv=all_inventory(me);
		sizeinv=sizeof(inv);
	
		while (sizeinv--)
		{
       			if (inv[sizeinv]->is_character())  
     				return notify_fail("�����ȥ�����˿ڣ�\n");
       		
		}
		
	}

	return ::valid_leave(me, dir);
}
