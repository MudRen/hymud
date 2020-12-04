#include <ansi.h>

string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});

string *typew=({
"sword",
"blade",
"hammer",
"whip",
"club",
"staff",
"throwing",
"dagger",
"axe",
});
string *typea=({
"hands",
"cloth",
"armor",
"boots",
"head",
"neck",
"surcoat",
"shield",
"waist",
"wrists",
});
mapping *TYPE1 = ({
        (["TYPE1":"SWORD","TYPE2":"sword","TYPE3":"��","TYPE4":"��"]),
        (["TYPE1":"BLADE","TYPE2":"blade","TYPE3":"��","TYPE4":"��"]),
        (["TYPE1":"HAMMER","TYPE2":"hammer","TYPE3":"��","TYPE4":"��"]),
        (["TYPE1":"WHIP","TYPE2":"whip","TYPE3":"��","TYPE4":"��"]),
        (["TYPE1":"CLUB","TYPE2":"club","TYPE3":"��","TYPE4":"��"]),
        (["TYPE1":"STAFF","TYPE2":"staff","TYPE3":"��","TYPE4":"��"]),
        (["TYPE1":"THROWING","TYPE2":"throwing","TYPE3":"����","TYPE4":"֧"]),        	        	        	
        (["TYPE1":"DAGGER","TYPE2":"dagger","TYPE3":"ذ��","TYPE4":"��"]),        	        	        	        	
        (["TYPE1":"AXE","TYPE2":"axe","TYPE3":"��","TYPE4":"��"]), 	
});

mapping *TYPE2 = ({
        (["TYPE1":"HANDS","TYPE2":"hands","TYPE3":"����","TYPE4":"��"]),
        (["TYPE1":"CLOTH","TYPE2":"cloth","TYPE3":"��װ","TYPE4":"��"]),
        (["TYPE1":"ARMOR","TYPE2":"armor","TYPE3":"����","TYPE4":"��"]),
        (["TYPE1":"BOOTS","TYPE2":"boots","TYPE3":"ѥ","TYPE4":"˫"]),
        (["TYPE1":"HEAD","TYPE2":"head","TYPE3":"ͷ��","TYPE4":"��"]),
        (["TYPE1":"NECK","TYPE2":"neck","TYPE3":"����","TYPE4":"��"]),
        (["TYPE1":"SURCOAT","TYPE2":"surcoat","TYPE3":"�Ǵ�","TYPE4":"��"]),
        (["TYPE1":"SHIELD","TYPE2":"shield","TYPE3":"��","TYPE4":"��"]),
        (["TYPE1":"WAIST","TYPE2":"waist","TYPE3":"����","TYPE4":"��"]),        	        	        	
        (["TYPE1":"WRISTS","TYPE2":"wrists","TYPE3":"����","TYPE4":"˫"]),        	        	        	        	
        	
});


mapping *TYPE3 = ({
        (["TYPE1":HIY"��"NOR,"TYPE2":"wtypeA"]),
        (["TYPE1":CYN"ľ"NOR,"TYPE2":"wtypeB"]),
        (["TYPE1":GRN"ˮ"NOR,"TYPE2":"wtypeC"]),
        (["TYPE1":RED"��"NOR,"TYPE2":"wtypeD"]),
        (["TYPE1":YEL"��"NOR,"TYPE2":"wtypeE"]),
        (["TYPE1":HIM"��"NOR,"TYPE2":"wtypeF"]),
        (["TYPE1":HIW"��"NOR,"TYPE2":"wtypeG"]),
        (["TYPE1":HIB"��"NOR,"TYPE2":"wtypeH"]),
        (["TYPE1":WHT"��"NOR,"TYPE2":"wtypeI"]),
        (["TYPE1":BBLK"��"NOR,"TYPE2":"wtypeJ"]),
        (["TYPE1":HIC"��"NOR,"TYPE2":"wtypeK"]),
        (["TYPE1":HIR"ħ"NOR,"TYPE2":"wtypeL"]),        	        	        	        	        	        	        	        	        	        	        	    	        	        	        	
        	
});

static mapping	Special_Class =	([
RED"�ɽ�" : ([	"id": "ganjiang",
		"long2"	: RED"�ɽ������ޱȣ��ܿ���ٵأ�������ħ��\n"NOR,
		"weapon_prop":         ([ "damage":70 ]),//180
		"sharpness":	       10,
		"rigidity":	       9,
		]),
RED"Īа" : ([	"id": "moye",
		"long2"	: RED"Īа�����ޱȣ��ܿ���ٵأ�������ħ��\n"NOR,
		"weapon_prop":         ([ "damage":70 ]),//130
		"sharpness":	       15,
		"rigidity":	       9,
		]),
RED"�㳦" : ([	"id": "yuchang",
		"long2"	: RED"�㳦�����ޱȣ��ܿ���ٵأ�������ħ��\n"NOR,
		"weapon_prop":         ([ "damage":70 , "attack":150 ]),//100
		"sharpness":	       8,
		"rigidity":	       7,
		]),
RED"̫��" : ([	"id": "taie",
		"long2"	: RED"̫������֮������֮�ܺ������£�Ī�в��ӣ�\n"NOR,
		"weapon_prop":         ([ "damage":70 , "qi":2000 , "jing":1000 ]),//100
		"sharpness":	       7,
		"rigidity":	       9,
		]),
RED"����" : ([	"id": "juque",
		"long2"	: RED"���ڼ�Ӳ�ޱȣ��ܿ���ٵأ�������ħ��\n"NOR,
		"weapon_prop":         ([ "damage":70 ]),//120
		"sharpness":	       7,
		"rigidity":	       20,
		]),
RED"����" : ([	"id": "chungou",
		"long2"	: RED"������˧֮������֮�ܻӾ����򣬿˵���ʤ��\n"NOR,
		"weapon_prop":         ([ "damage":70 , "jingli":1000 , "neili":2000 ]),//120
		"sharpness":	       7,
		"rigidity":	       8,
		]),
RED"տ¬" : ([	"id": "zhanlu",
		"long2"	: RED"տ¬��������������Ӳ���ھ���������ǧ�������\n"NOR,
		"weapon_prop":         ([ "damage":70 ]),//160
		"sharpness":	       12,
		"rigidity":	       12,
		]),
RED"����" : ([	"id": "gongbu",
		"long2"	: RED"�����������죬���ܲ��̣�\n"NOR,
		"weapon_prop":         ([ "damage":70 , "attack":100 , "parry":75 , "dodge":75 ]),//70
		"sharpness":	       10,
		"rigidity":	       9,
		]),
RED"ʤа" : ([	"id": "shengxie",
		"long2"	: RED"ʤа�����޴�����κ�Ҫ��\n"NOR,
		"weapon_prop":         ([ "damage":70 ]),//70
		"sharpness":	       8,
		"rigidity":	       9,
		"wield_maxneili":      0,
		"wield_neili":	       0,
		"wield_str":	       0,
		]),
RED"��Ȫ" : ([	"id": "longquan",
		"long2"	: RED"��Ȫ�˼伫Ʒ������������\n"NOR,
		"weapon_prop":         ([ "damage":100 , "dexerity":5 , "strength":5 , "constitution":5 , "intelligence":5 ]),
		"sharpness":	       9,
		"rigidity":	       7,
		]),
]);

static mapping	Super_Class = ([
	HIM"��ԯ" : ([	"id":	"xuanyuan",	
			"long2": HIM"���ջƵ۳ִ�������ָ�ϳ��ϣ�������ɨ��������Ӧ�����ɣ������޶�ս��ȣ�\n"NOR,
		]),
	HIR"��ͨ" : ([	"id":	"shentong",
			"long2":	HIR"�����ͨ������Ҫƽ�ƣ���Ҫ���У����۹˼⣬���������ȣ�
������Ȼ����������࣬������ͣ�磬���绨��������ֶ���\n"NOR,
		]),
	HIG"�޼�" : ([	"id":	"wuji",		
			"long2": HIG"�����Ѵ�����뻯���Ƿ��켫���������֮���磡��˵������ڣ������⡰�޼�����\n"NOR,
		]),
	HIW"����" : ([	"id":	"bagua",	
			"long2": HIW"�����С��ݡ����������ˡ����š�������������������������֮�𣬴��������򣬼����������һ��\n"NOR,
		]),
	HIB"������˹" :	([	"id":	"joeywus",	
			"long2": HIB"������������ͳ�ε�ʱ��������ӵĽ�Ҳ��ֵ��ͷĸţ�ļ�Ǯ�����������Լ����ǰѴ���ʽ
�������������˹����˵�ǰ��˰���ġ�Τ�����������죬�˵����������\n"NOR,
		]),
	HIW"̫��" : ([	"id":	"taibai",	
			"long2": HIW"
		�Կ��Ϻ�ӧ  �⹳˪ѩ��		�����հ���  ��������
		ʮ��ɱһ��  ǧ�ﲻ����		���˷���ȥ  ���������
		�й�������  �ѽ�ϥǰ��		���ˡ��캥  ����Ȱ����
		������Ȼŵ  ������Ϊ��		�ۻ�������  ����������
		���Իӽ��  ��������		ǧ���׳ʿ  ���մ�����
		����������  ��������Ӣ		˭�������  ����̫����\n"NOR,
		]),
	HIY"Ǭ��" : ([	"id":	"qiankun",	
			"long2": HIY"�����������߷ֱ��Ժڰ����������������ɣ�һ��һ�ף��к�Ǭ������������֮������һ�����\n"NOR,
		]),
	HIY"̫��" : ([	"id":	"taiji",	
			"long2": HIY"̫���ߣ��޼�����������֮ĸҲ����֮��֣���֮��ϡ��޹��������������졣
�˸�����ν֮�ߣ���˳�˱�ν֮ճ��������Ӧ���������档��仯��ˣ���
��Ϊһ�ᣡ\n"NOR,
		]),
	HIC"���" : ([	"id":	"tiandi",	
			"long2": HIC"���֮����Ů洲��������µ���ؼ�����֮��֮һ��ǧ���������ƣ����ܿ������أ�\n"NOR,
		]),
	HIM"����" : ([	"id":	"fengyun",	
			"long2": HIM"��ν���Ƽʻᣬ��ر�ɫ���̴���ǧ���ħС����һ����\n"NOR,
		]),
	HIG"����" : ([	"id":	"haoqi",	
			"long2": HIG"��غ���֮�����ɨħ������Ϊ��Ϊ����֮���ߣ�\n"NOR,
		]),
	HIR"����" : ([	"id":	"lianyu",	
			"long2": HIR"��ʮ�������еأ������гǣ�������ǣ���С��ħ�������������ڴ��ֻ�������ν֮����������\n"NOR,
		]),
	HIC"����" : ([	"id":	"sanqing",	
			"long2": HIC"����������������Σ������컯��һ�����壡����ǡ�����һ����塣��\n"NOR,
		]),
	HIC"����" : ([	"id":	"kunlun",	
			"long2": HIC"	Ц�����˼�ʮ���Σ��ո�����ͷ��
	��ͭ���ﲴ���������죬�������ƣ� 
	����ʫ���ζϣ��Ϲ����� 
	�ѽ���Ȼ�����޴��й��ۡ� 
 
	��������·Զ����˭�����壬ŪӰ���ޣ�
	��Ӣ�۶�Ů�������Ž�
	�����ܵƻ����ʣ���꼻�һ�ֺ����ݣ�
	Ʈ��ߣ��������ƴ����� \n"NOR,
		]),
]);


static mapping	Great_Class = ([
	CYN"����":	"diwang",	CYN"����":	"wangzhe",
	CYN"���":	"tianhou",	CYN"����":	"bawang",   
	CYN"��ʥ":	"tiansheng",	CYN"����":	"shenwang",   
	CYN"����":	"yaohou",	BLU"����":	"gonghou", 
	BLU"ħ��":	"mowang",	BLU"����":	"qixing", 
	BLU"���":	"egui",		GRN"����":	"yulong", 
	GRN"���":	"yufeng",	GRN"�ɺ�":	"songhe",
	GRN"����":	"tianlong",	GRN"����":	"dilong",
	GRN"���":	"tianfeng",	GRN"�ط�":	"difeng",
	GRN"����":	"longxiang",	GRN"����":	"fengwu",
	HIG"��Ӱ":	"wuying",	HIG"�Ƽ�":	"pojia",
	HIG"����":	"feilong",	HIG"����":	"wuyi",
	HIG"����":	"niaoxiang",	HIG"����":	"wanpan",
	HIG"��Ƽ":	"qingping",	YEL"����":	"huanglong",
	WHT"����":	"yunti",	WHT"̫Ԩ":	"taiyuan",
	WHT"̫��":	"taifeng",	WHT"����":	"xuling",
	WHT"����":	"pili",		WHT"�׵�":	"leidian",
	WHT"����":	"fenglei",	WHT"���":	"zhendian",
	WHT"����":	"baiyu",	WHT"����":	"qingyu",
	WHT"����":	"ziyu",		WHT"����":	"lanyu",
	WHT"����":	"luyu",		WHT"����":	"huangyu",
	WHT"����":	"chiyu",	WHT"����":	"hongyu",
	CYN"���":	"qinghong",	CYN"�׺�":	"baihong",
	CYN"�Ϻ�":	"zihong",	CYN"����":	"lanhong",
	CYN"�̺�":	"luhong",	CYN"���":	"chihong",
	CYN"��Ӱ":	"huanying",	CYN"��˪":	"ningshuang",
	CYN"����":	"qingsuo",	MAG"����":	"tianlong",
	MAG"�ϵ�":	"zidian",	MAG"���":	"fenghuang",
	MAG"����":	"tianqu",	MAG"���":	"tianxuan",
	MAG"����":	"tianji",	MAG"��Ȩ":	"tianquan",
	MAG"���":	"yuheng",	MAG"����":	"kaiyang",
	MAG"ҡ��":	"yaoguang",	MAG"����":	"beidou",
	HIR"���":	"tianhuo",	HIR"����":	"qilin",
	HIR"��а":	"pixie",	YEL"���":	"hongjun",
	YEL"���":	"guangcheng",	YEL"���":	"jinguang",
	YEL"����":	"xiuluo",	YEL"ҹ��":	"yecha",
	YEL"����":	"yaochi",	YEL"���":	"leiheng",
	HIR"����":	"huolong",	HIC"����":	"binglong",
	HIB"����":	"heilong",	HIR"����":	"yanlong",
	HIC"����":	"qinglong",	HIR"��ȸ":	"zhuque",
	HIW"�׻�":	"baihu",	HIB"����":	"xuanwu",	
	GRN"����":	"xuanji",	HIG"����":	"jiutian",
	HIG"����":	"jiuyou",	MAG"����":	"jiulong",
	MAG"����":	"wulong",	MAG"����":	"sanlong",
	WHT"����":	"shengsi",
]);

static string *G_3_class = ({
	"����",	"����",	"����",	"����",	"����",	"�ĺ�",	"���",	"��÷",
	"��Ȫ",	"��Ȫ",	"��Ȫ",	"��Ȫ",	"ŭ��",	"����",	"����",	"��ˮ",
	"���",	"˫��",	"����",	"��ʤ",	"�⹳",	"�һ�",	"�޵�",	"˫��",	
	"����",	"��Ů",	"����",	"����",	"����",	"��",	"����",	"�̹�",
	"����",	"��ˮ",	"ܽ��",	"��Ԩ",	"��ɽ",	"��",	"����",	"����",
	"����",	"��Ƥ",	"��ɽ",	"����",	"����",	"���",	"�׺�",	"����",	
	"����",	"����",	"����",	"��β",	"���",	"���",	"����",	"����",	
	"���",	"����",	"��ͷ",	"����",	"ţͷ",	"�л�",	"����",	"����",	
	"����",	"�պ�",	"����",	"��ͷ",	"�ͻ�",	"���",	"��ˮ",	"����",
	"�޹�",	"����",	"���",	"���",	"����",	"��Ʒ",	"��ˮ",	"��ˮ",
	"���",	"�ط�",	"����",	"����",	"����",	"����",	"����",	"ħ��",
	"��ˮ",	"��ˮ",	"ħˮ",	"����",	"�岽",	"��Ҷ",	"��Ҷ",	"����",
	"����",	"����",	"ħ��",	"�˺�",	"����",	"�ͻ�",	"��ʨ",	"Х��",
	"�÷�",	"����",	"����",	"����",	"����",	"����",	"����",	"ʨ��",
	"Ұ��",	"����",	"����",	"����",	"��ʨ",	"��",	"��",	"��ӥ",
	"����",	"����",	"���",	"����",	"�ڷ�",	"����",	"����",	"����",
	"��ü",	"����",	"����",	"����",	"�촽",	"��",	"��ָ",	"�ر�",
	"����",	"����",	"ҹ��",	"��ݺ",	"����",	"����",	"����",	"����",
	"ҹ��",	"����",	"����",	"����",	"����",	"����",	"����",	"����",
	"����",	"����",	"����",	"ʨ��",	"�Ի�",	"����",	"�Ͼ�",	"��ĸ",
	"����",	"����",	"����",	"��İ",	"�ݺ�",	"����",	"����",	"���",
});


static string *G_4_class = ({
	"�ɰ�",	"����",	"���",	"����",	"����",	"���",	"ʥĸ",	"�Ĳ�",
	"��ʥ",	"����",	"����",	"����",	"����",	"��ѩ",	"Ʈѩ",	"��ѩ",
	"��ѩ",	"��ѩ",	"ѩ��",	"����",	"ϼε",	"��ϼ",	"����",	"嫺�",
	"ĵ��",	"�ٺ�",	"�׺�",	"����",	"����",	"���",	"��÷",	"����",
	"��˼",	"����",	"����",	"��ҩ",	"�ž�",	"õ��",	"�¼�",	"�ļ�",
	"ܽ��",	"Ǿޱ",	"����",	"��ʦ",	"ϴ��",	"����",	"����",	"��ħ",
	"�L�",	"�L��",	"���",	"���",	"��ޱ",	"ľ��",	"���F",	"̫�",
	"���Q",	"���Q",	"���Q",	"���Q",	"��ޱ",	"��ޱ",	"��ޱ",	"��ޱ",
	"��ޱ",	"���",	"���",	"���",	"���",	"���",	"��з",	"��ţ",
	"�۹�",	"����",	"����",	"����",	"����",	"����",	"����",	"��ɽ",
	"����",	"ժ��",	"̽��",	"����",	"����",	"��Ӱ",	"��ħ",	"����",
	"����",	"ǧ��",	"����",	"ǧâ",	"����",	"ħ��",	"���",
	"�Ͼ�",	"��ҳ",	"����",	"���",	"����",	"����",	"����",	"��ͼ",
	"Ѫն", "����", "����", "��â", "����", "����", "����", "����",
	"����", "Ӱ��", "���", "����", "˫��", "��ϼ", "����", "����",
	"����", "����", "�ۺ�", "��̳", "����", "����", "�ɷ�", "����",
	"��Ȫ",
});

static string *G_5_class = ({
	"��",	"��",	"С",	"��",	"��",	"��",	"��",	"��",
	"��",	"��",	"��",	"��",	"��",	"��",	"ͭ",	"��",

});

mapping *BOOK1 = ({
        (["TYPE1":"�Ṧ","TYPE2":"dodge"]),
        (["TYPE1":"����","TYPE2":"axe"]),
        (["TYPE1":"����","TYPE2":"blade"]),
        (["TYPE1":"צ��","TYPE2":"claw"]),
        (["TYPE1":"����","TYPE2":"club"]),
        (["TYPE1":"ȭ��","TYPE2":"cuff"]),
        (["TYPE1":"ָ��","TYPE2":"finger"]),
        (["TYPE1":"�ڹ�","TYPE2":"force"]),
        (["TYPE1":"����","TYPE2":"hammer"]),
        (["TYPE1":"�ַ�","TYPE2":"hand"]),
        (["TYPE1":"�ȷ�","TYPE2":"leg"]),
        (["TYPE1":"�м�","TYPE2":"parry"]),
        (["TYPE1":"�ȷ�","TYPE2":"staff"]),        	        	        	        	        	        	        	        	        	        	        	    	        	        	        	
        (["TYPE1":"�Ʒ�","TYPE2":"strike"]),
        (["TYPE1":"����","TYPE2":"sword"]),
        (["TYPE1":"����","TYPE2":"throwing"]),
        (["TYPE1":"ȭ��","TYPE2":"unarmed"]),
        (["TYPE1":"�޷�","TYPE2":"whip"]),  
        	
});



string s_good(int i)
{
	switch(i){
		case 10..60:	return "�ޱ�";	
		case 9:		return "�ޱ�";	
		case 8:		return "����";	
		case 7:		return "����";	
		case 6:		return "��Ϊ";	
		case 5:		return "�൱";	
		case 4:		return "ʮ��";	
		case 3:		return "�ǳ�";	
		case 2:		return "�Ƚ�";	
		case 1:		return "����";	
		case -1:	return "����ô";	
		case -2:	return "�ܲ�";	
		case -3:	return "����";	
		default:	return "һ��";	
	}
}


static mapping MDESC_WEAPON = ([
	"hantie":         HIC"���꺮����"NOR,
	"xuantie":	  WHT"����"NOR,
	"shentie":        RED"��������"NOR,
	"jintie":         HIY"����"NOR,
	"ruanying":       HIW"����"NOR,
	"liuhuashi":      RED"����ʯ"NOR,
	"lushi":          HIG"��ʯ"NOR,
	"ruantie":        YEL"����"NOR,
	"shengtie":       YEL"����"NOR,
	"qingtong":       GRN"��ͭ"NOR,
	"default":        "����",
]);

static mapping MDESC_ARMOR = ([
	"longcansi":      HIY"�����˿"NOR,
	"tiancansi":      WHT"���˿"NOR,
	"bingcansi":      HIW"����˿"NOR,
	"yucansi":        GRN"���˿"NOR,
	"mumianhua":      HIY"ľ�޻�"NOR,
	"cansi":          HIW"��˿"NOR,
	"zhuma":          HIY"����"NOR,
	"dama":           YEL"����"NOR,
	"yama":           YEL"����"NOR,
	"mianhua":        HIW"�޻�"NOR,
	"default":        "����",
]);

static mapping MDESC_WYU = ([
	"youyu":          HIW"���"NOR,
	"duyu":           YEL"����"NOR,
	"nanyu":          HIY"����"NOR,
	"miyu":        HIB"����"NOR,
	"fengleiyu":      GRN"������"NOR,
	"longlingyu":          HIY"������"NOR,
	"default":        HIW"���"NOR,
]);

static mapping MDESC_AYU = ([
	"banyu":          HIW"���"NOR,
	"liuyu":           YEL"����"NOR,
	"zhiyu":          HIY"֬��"NOR,
	"xiangniyu":        HIB"������"NOR,
	"lvyusui":      GRN"������"NOR,
	"fenglingyu":          GRN"�����"NOR,
	"default":        HIW"���"NOR,
]);

string s_power(int i)
{
	if( i >= 1500 )	return HIR"�������"NOR;
	if( i >= 1280 )	return HIR"��Ԫ����"NOR;	
	if( i >= 1000 )	return HIR"������˫"NOR;	
	if( i >= 920 )	return HIM"��������"NOR;	
	if( i >= 800 )	return HIY"������ƥ"NOR;
	if( i >= 780 )	return HIG"��������"NOR;
	if( i >= 660 )	return HIB"��������"NOR;
	if( i >= 560 )	return HIC"ն����ħ"NOR;
	if( i >= 460 )	return RED"�����ױ�"NOR;
	if( i >= 300 )	return MAG"�������"NOR;
	if( i >= 280 )	return YEL"�ܸ�"NOR;
	if( i >= 160 )	return GRN"ˮ׼����"NOR;
	if( i >= 120 )	return BLU"����"NOR;
	if( i >	60 )	return CYN"��С"NOR;
	if( i >= 1 )	return CYN"һ��"NOR;	
	if( i <= 0 )	return "����";
	if( i <= -20 )	return "����";
	return "һ��";
}


string s_powera(int i)
{
	if( i >= 500 )	return HIR"�������"NOR;
	if( i >= 480 )	return HIR"��Ԫ����"NOR;	
	if( i >= 400 )	return HIR"������˫"NOR;	
	if( i >= 380 )	return HIM"��������"NOR;	
	if( i >= 350 )	return HIY"������ƥ"NOR;
	if( i >= 300 )	return HIG"��������"NOR;
	if( i >= 280 )	return HIB"��������"NOR;
	if( i >= 250 )	return HIC"ն����ħ"NOR;
	if( i >= 200 )	return RED"�����ױ�"NOR;
	if( i >= 180 )	return MAG"�������"NOR;
	if( i >= 150 )	return YEL"�ܸ�"NOR;
	if( i >= 100 )	return GRN"ˮ׼����"NOR;
	if( i >= 80 )	return BLU"����"NOR;
	if( i >	50 )	return CYN"��С"NOR;
	if( i >= 1 )	return CYN"һ��"NOR;	
	if( i <= 0 )	return "����";
	if( i <= -20 )	return "����";
	return "һ��";
}


string *gems_level = ({
	"ϸ���",
	"�ֲڵ�",
	"��׼��",
	"���µ�",
	"������",
        "������",
        "ħ����",
        "��ʥ��",
});

string w_power(int i)
{
	if( i >= 16 )	return HIY"����"NOR;
  if( i >= 15 )	return HIR"����"NOR;
	if( i >= 14 )	return HIR"����"NOR;
	if( i >= 13 )	return HIR"��Ԫ"NOR;	
	if( i >= 12 )	return HIR"��˫"NOR;	
	if( i >= 11 )	return HIM"����"NOR;	
	if( i >= 10 )	return HIY"��ʥ"NOR;
	if( i >= 9 )	return HIG"ħ��"NOR;
	if( i >= 8 )	return HIB"����"NOR;
	if( i >= 7 )	return HIC"����"NOR;
	if( i >= 6 )	return RED"����"NOR;
	if( i >= 5 )	return MAG"��׼"NOR;
	if( i >= 4 )	return YEL"�ܸ�"NOR;
	if( i >= 3 )	return GRN"�ֲ�"NOR;
	if( i >= 2 )	return BLU"ϸ��"NOR;
	if( i >=	1  )	return CYN"����"NOR;
	if( i <= 0 )	return "����";
	return "����";
}

string w_power2(int i)
{
	if( i >= 200 )	return HIY"����"NOR;
  if( i >= 180 )	return HIR"����"NOR;
	if( i >= 160 )	return HIR"����"NOR;
	if( i >= 130 )	return HIR"��Ԫ"NOR;	
	if( i >= 120 )	return HIR"��˫"NOR;	
	if( i >= 110 )	return HIM"����"NOR;	
	if( i >= 100 )	return HIY"��ʥ"NOR;
	if( i >= 90 )	return HIG"ħ��"NOR;
	if( i >= 80 )	return HIB"����"NOR;
	if( i >= 70 )	return HIC"����"NOR;
	if( i >= 60 )	return RED"����"NOR;
	if( i >= 50 )	return MAG"��׼"NOR;
	if( i >= 40 )	return YEL"�ܸ�"NOR;
	if( i >= 30 )	return GRN"�ֲ�"NOR;
	if( i >= 20 )	return BLU"ϸ��"NOR;
	if( i >	10  )	return CYN"����"NOR;
	if( i >	5  )	return YEL"һ��"NOR;
	if( i >=	1  )	return GRN"����"NOR;
	if( i <= 0 )	return "����";
	return "����";
}

string s_good2(int i)
{
	switch(i){
    case 6:		return MAG"�������"NOR;	
		case 5:		return HIC"��˫�޶�"NOR;	
		case 4:		return WHT"������˫"NOR;	
		case 3:		return HIB"��������"NOR;	
		case 2:		return RED"��������"NOR;	
		case 1:		return GRN"����ϸ��"NOR;	
		default:	return YEL"һ�����"NOR;	
	}
}



string *du=({
"ice_poison",
"ill_dongshang",
"ill_fashao",
"ill_kesou",
"ill_shanghan",
"ill_zhongshu",
"xx_poison",
"cold_poison",
"flower_poison",
"rose_poison",
"x2_poison",
"sanpoison",
"scorpion_poison",
"qx_snake_poison",
"anqi_poison",
"yf_poison",
"nx_poison",
"chilian_poison",
"yufeng_poison",
"insect_poison",
"xscold_poison",
});


int weaponmake(int sl,int ty,int lv,int zl,string path)
{
	string weaponname,weaponid,weaponlong,str,material,strn,strnf;
	object *user, newob,me;
	object *inv;
	int i,rigidity,w;
  object conc;
	//object env;
	string this_file;
	string my_file;
	string name;
	string file;
	//string c_name,o_name;
  mapping type;
  int weighttext;
  int valuetext;
  int weilitext;
  int sharpness;
  int gifttext;
  int sztest;
  int fhtest;
  int skilllevtext;
  int is,lev;
  int basegifttext,basesztest,basefhtest;
  int yushi,color;
  me=this_player();
	

  color=random(13);

//message_vision("$N��ͷ����$n˵����ɫ�ǵ�"+color+"�֣�\n", this_object(), me);
//return notify_fail("�����������Ӱɡ�\n");


	//wiz_status = SECURITY_D->get_status(me);
seteuid(getuid());

//	if( wiz_status != "(admin)" && wiz_status != "(arch)" )
//		return notify_fail("ֻ�� (arch) ���ϵ���ʦ����ʹ��!\n");


//	name = (string)me->query("id")+"_w"+me->query_temp("item/dzwz");

//write("AAA");
//write(TYPE3[0]["TYPE1"]);
//return 1;
//		i = random(sizeof(Great_Class));
//write(keys(Great_Class)[i]);
//write(Great_Class[keys(Great_Class)[i]]);

my_file = read_file("/obj/ritem/WEAPON.o");
//������0-8
type = TYPE1[ty];

//�ȼ�����1-6
lev = lv;
//���Ͼ��ȼ���

//��ʯ����
yushi=lv/2+2;
//��ʯ���ȼ���

//���ϲ���

//���ϲ���
//if (lv>3) lv=lv+random(4);

	switch(lv){
		case 1:	material="qingtong"; break;
		case 2:	material="shengtie"; break;
case 3:	material="ruantie"; break;
case 4:	material="lushi"; break;				
case 5:	material="liuhuashi"; break;
case 6:	material="ruanying"; break;				
case 7:	 material="jintie"; break;	
case 8:	material="shentie";	 break;	
case 9:	material="xuantie";	 break;	
case 10:	material="hantie";	 break;	
		default: material="qingtong";	break;
	}
	
		






//�����ɲ��Ͼ���
weighttext=1000+random(15000);




//write(lev+"");
//return 1;
if (lev==6)
{
		i = zl;
		weaponname	= keys(Special_Class)[i];
    weaponid	=  Special_Class[weaponname]["id"] + " " + type["TYPE2"];
    weaponlong = Special_Class[weaponname]["long2"];
		weaponname	= keys(Special_Class)[i] + "֮" + type["TYPE3"]+NOR;
//����ѧϰ������
i=random(sizeof(BOOK1));		
//Ӳ��
rigidity=6+random(25);
//��ֵ
valuetext=6000*lev;
//����
weilitext=100*lev+random(1000);
//����
sharpness=3*lev+random(10);
//�������Ը���
basegifttext=6*lev;
//��������
basesztest=6*lev;
//��������
basefhtest=6;
//����ѧϰ�书�ĵȼ�
skilllevtext=80*lev;
//���ֵĻ���
is=3;
}
else
if (lev==5)
{
		i = zl;
		weaponname	= keys(Super_Class)[i];
    weaponid	=  Super_Class[weaponname]["id"] + " " + type["TYPE2"];
    weaponlong = Super_Class[weaponname]["long2"];
		weaponname	= keys(Super_Class)[i] + "֮" + type["TYPE3"]+NOR;

//����ѧϰ������
i=random(sizeof(BOOK1));		
//Ӳ��
rigidity=5+random(25);
//��ֵ
valuetext=5000*lev;
//����
weilitext=100*lev+random(800);
//����
sharpness=3*lev+random(8);
//�������Ը���
basegifttext=5*lev;
//��������
basesztest=5*lev;
//��������
basefhtest=5;
//����ѧϰ�书�ĵȼ�
skilllevtext=60*lev;
//���ֵĻ���
is=5;

}		
else
if (lev==4)
{
		i = zl;
		weaponname	= keys(Great_Class)[i];
    weaponid	=  Great_Class[keys(Great_Class)[i]] + " " + type["TYPE2"];
    weaponlong = keys(Great_Class)[i] + "֮" + type["TYPE3"]+NOR;
		weaponname	= keys(Great_Class)[i] + "֮" + type["TYPE3"]+NOR;
//����ѧϰ������
i=random(sizeof(BOOK1));		
//Ӳ��
rigidity=4+random(22);
//��ֵ
valuetext=4000*lev;
//����
weilitext=100*lev+random(600);
//����
sharpness=3*lev+random(7);
//�������Ը���
basegifttext=4*lev;
//��������
basesztest=4*lev;
//��������
basefhtest=4;
//����ѧϰ�书�ĵȼ�
skilllevtext=80*lev;
//���ֵĻ���
is=6;
}		
else
if (lev==3)
{
		i = zl;
		weaponname	= G_3_class[i];
    weaponid	=  "good " + type["TYPE2"];
    weaponlong = G_3_class[i] + "֮" + type["TYPE3"]+NOR;
		weaponname	= order[color] +G_3_class[i] + "֮" + type["TYPE3"]+NOR;
//����ѧϰ������
i=random(sizeof(BOOK1));		
//Ӳ��
rigidity=3+random(20);
//��ֵ
valuetext=3000*lev;
//����
weilitext=100*lev+random(500);
//����
sharpness=3*lev+random(5);
//�������Ը���
basegifttext=3*lev;
//��������
basesztest=3*lev;
//��������
basefhtest=3;
//����ѧϰ�书�ĵȼ�
skilllevtext=80*lev;
//���ֵĻ���
is=7;

}		
else
if (lev==2)
{
		i = zl;
		weaponname	= G_4_class[i];
    weaponid	=  "general " + type["TYPE2"];
    weaponlong = G_4_class[i] + "֮" + type["TYPE3"]+NOR;
		weaponname	= order[color] +G_4_class[i] + "֮" + type["TYPE3"]+NOR;
//����ѧϰ������
i=random(sizeof(BOOK1));		
//Ӳ��
rigidity=2+random(15);
//��ֵ
valuetext=2000;
//����
weilitext=100+random(400);
//����
sharpness=3+random(4);
//�������Ը���
basegifttext=2;
//��������
basesztest=2;
//��������
basefhtest=2;
//����ѧϰ�书�ĵȼ�
skilllevtext=120;
//���ֵĻ���
is=8;

}
else
if (lev==1)
{
		i = zl;
		weaponname	= G_5_class[i];
    weaponid	=  "bad " + type["TYPE2"];
    weaponlong = G_5_class[i] + "֮" + type["TYPE3"]+NOR;
		weaponname	= order[color] +G_5_class[i] + "֮" + type["TYPE3"]+NOR;
//����ѧϰ������
i=random(sizeof(BOOK1));		
//Ӳ��
rigidity=1+random(10);
//��ֵ
valuetext=2000;
//����
weilitext=50+random(300);
//����
sharpness=1+random(5);
//�������Ը���
basegifttext=1;
//��������
basesztest=1;
//��������
basefhtest=1;
//����ѧϰ�书�ĵȼ�
skilllevtext=50;
//���ֵĻ���
is=9;
}
is=is+5-yushi;
if (yushi==6 && is>6) is=6;
if (yushi==5 && is>7) is=7;
if (yushi==4 && is>8) is=8;
if (yushi==3 && is>9) is=9;


  if (type["TYPE2"]=="throwing" )
{
if (strsrch(my_file,"weaponamount")> 1)
{
	weighttext=weighttext/20+1;
    my_file= replace_string(my_file,"weaponamount","1");
}
}
else
{
if (strsrch(my_file,"set_amount(weaponamount);")> 1)
{
	my_file= replace_string(my_file,"set_amount(weaponamount);","");
}
}






//my_file= replace_string(my_file,"materialtext","default");

my_file= replace_string(my_file,"sharpnesstext",""+sharpness+"");
strn="����:"+w_power(sharpness)+" ";


my_file= replace_string(my_file,"weighttext",weighttext+"");


	my_file= replace_string(my_file,"ownertext",	me->query("id"));
	my_file= replace_string(my_file,"ownernametext",	me->query("name"));
  my_file= replace_string(my_file,"valuetext",	valuetext+"");
  my_file= replace_string(my_file,"weilitext",	weilitext+"");

if (random(is)==0)
{
gifttext=basegifttext+random(lev+8);
  my_file= replace_string(my_file,"inttext",	gifttext+"");
strn +="����:"+w_power2(gifttext)+" ";
}
else
{
  my_file= replace_string(my_file,"inttext","0");		
}

if (random(is)==0)
{
gifttext=basegifttext+random(lev+8);
  my_file= replace_string(my_file,"strtext",	gifttext+"");
strn +="����:"+w_power2(gifttext)+" ";
}
else
{
  my_file= replace_string(my_file,"strtext","0");
}

if (random(is)==0)
{
gifttext=basegifttext+random(lev+8);
  my_file= replace_string(my_file,"kartext",	gifttext+"");
strn +="��Դ:"+w_power2(gifttext)+" "+"\n";
}
else
{
  my_file= replace_string(my_file,"kartext",	"0");
}

if (random(is)==0)
{
gifttext=basegifttext+random(lev+8);
  my_file= replace_string(my_file,"pertext",	gifttext+"");
strn +="����:"+w_power2(gifttext)+" ";
}
else
{
my_file= replace_string(my_file,"pertext",	"0");
}

if (random(is)==0)
{
gifttext=basegifttext+random(lev+8);
  my_file= replace_string(my_file,"dextext",	gifttext+"");
strn +="��Ԩ:"+w_power2(gifttext)+" ";
}
else
{
my_file= replace_string(my_file,"dextext",	"0");
}

if (random(is)==0)
{
gifttext=basegifttext+random(lev+8);
  my_file= replace_string(my_file,"context",	gifttext+"");      
strn +="����:"+w_power2(gifttext)+" ";
}
else
{
my_file= replace_string(my_file,"context",	"0");      
}

if (random(is)==0)
{
sztest=basesztest+random(lev*10);
my_file= replace_string(my_file,"armortext",	sztest+"");  
strn +="����:"+w_power2(sztest)+" "+"\n";
}
else
{
my_file= replace_string(my_file,"armortext",	"0");      
}

if (random(is)==0)
{
sztest=basesztest+random(lev*10);
my_file= replace_string(my_file,"defensetext",	sztest+""); 
strn +="����:"+w_power2(sztest)+" ";
}
else
{
my_file= replace_string(my_file,"defensetext",	"0");      
}

if (random(is)==0)
{
sztest=basesztest+random(lev*10);
my_file= replace_string(my_file,"dodgetext",	sztest+"");  
strn +="��ʯ:"+w_power2(sztest)+" ";
}
else
{
my_file= replace_string(my_file,"dodgetext",	"0");      
}

if (random(is)==0)
{
sztest=basesztest+random(lev*10);
my_file= replace_string(my_file,"parrytest",	sztest+"");  
strn +="��ʯ:"+w_power2(sztest)+" ";
}
else
{
my_file= replace_string(my_file,"parrytest",	"0");      
}

if (random(is)==0)
{
sztest=basesztest+random(lev*10);
my_file= replace_string(my_file,"attacktest",	sztest+"");  
strn +="����:"+w_power2(sztest)+" "+"\n";
}
else
{
my_file= replace_string(my_file,"attacktest",	"0");      
}

if (random(is)==0)
{ 
sztest=basesztest+random(lev*10);
my_file= replace_string(my_file,"neilitext",	sztest+"");  
strn +="����:"+w_power2(sztest)+" ";
}
else
{
my_file= replace_string(my_file,"neilitext",	"0");      
}

if (random(is)==0)
{ 
sztest=basesztest+random(lev*10);
my_file= replace_string(my_file,"qitext",	sztest+"");  
strn +="����:"+w_power2(sztest)+" ";
}
else
{
my_file= replace_string(my_file,"qitext",	"0");      
}

if (random(is)==0)
{ 
sztest=basesztest+random(lev*10);
my_file= replace_string(my_file,"jingtext",	sztest+"");  
my_file= replace_string(my_file,"jinglitext",	sztest+"");  
strn +="����:"+w_power2(sztest)+" ";
}
else
{
my_file= replace_string(my_file,"jingtext",	"0");   
my_file= replace_string(my_file,"jinglitext",	"0");      
}

if (random(is)==0)
{
sztest=basesztest+random(lev*10);
my_file= replace_string(my_file,"damagetext",	sztest+"");  
strn +="����:"+w_power2(sztest)+" ";
}
else
{
my_file= replace_string(my_file,"damagetext",	"0");      
}

my_file= replace_string(my_file,"skillnametext",	BOOK1[i]["TYPE2"]);  
my_file= replace_string(my_file,"skilllevtext",	skilllevtext+""); 


strnf="";
if (random(is)==0)
{
fhtest=basefhtest+random(5+lev);
my_file= replace_string(my_file,"wtypeAtext",	fhtest+"");
strnf=TYPE3[0]["TYPE1"]+":"+ w_power(fhtest) + " ";
}
else
{
my_file= replace_string(my_file,"wtypeAtext",	"0");
}

if (random(is)==0)
{
fhtest=basefhtest+random(5+lev);
my_file= replace_string(my_file,"wtypeBtext",	fhtest+"");
strnf +=TYPE3[1]["TYPE1"]+":"+ w_power(fhtest) + " ";
}
else
{
my_file= replace_string(my_file,"wtypeBtext",	"0");
}

if (random(is)==0)
{
fhtest=basefhtest+random(5+lev);
my_file= replace_string(my_file,"wtypeCtext",	fhtest+"");
strnf +=TYPE3[2]["TYPE1"]+":"+ w_power(fhtest) + " ";
}
else
{
my_file= replace_string(my_file,"wtypeCtext",	"0");
}

if (random(is)==0)
{
fhtest=basefhtest+random(5+lev);
my_file= replace_string(my_file,"wtypeDtext",	fhtest+"");
strnf +=TYPE3[3]["TYPE1"]+":"+ w_power(fhtest) + " ";
}
else
{
my_file= replace_string(my_file,"wtypeDtext",	"0");
}

if (random(is)==0)
{
fhtest=basefhtest+random(5+lev);
my_file= replace_string(my_file,"wtypeEtext",	fhtest+"");
strnf +=TYPE3[4]["TYPE1"]+":"+ w_power(fhtest) + " ";
}
else
{
my_file= replace_string(my_file,"wtypeEtext",	"0");
}

if (random(is)==0)
{
fhtest=basefhtest+random(5+lev);
my_file= replace_string(my_file,"wtypeFtext",	fhtest+"");
strnf +=TYPE3[5]["TYPE1"]+":"+ w_power(fhtest) + " \n";
}
else
{
my_file= replace_string(my_file,"wtypeFtext",	"0");
}

if (random(is)==0)
{
fhtest=basefhtest+random(5+lev);
my_file= replace_string(my_file,"wtypeGtext",	fhtest+"");
strnf +=TYPE3[6]["TYPE1"]+":"+ w_power(fhtest) + " ";
}
else
{
my_file= replace_string(my_file,"wtypeGtext",	"0");
}

if (random(is)==0)
{
fhtest=basefhtest+random(5+lev);
my_file= replace_string(my_file,"wtypeHtext",	fhtest+"");
strnf +=TYPE3[7]["TYPE1"]+":"+ w_power(fhtest) + " ";
}
else
{
my_file= replace_string(my_file,"wtypeHtext",	"0");
}

if (random(is)==0)
{
fhtest=basefhtest+random(5+lev);
my_file= replace_string(my_file,"wtypeItext",	fhtest+"");
strnf +=TYPE3[8]["TYPE1"]+":"+ w_power(fhtest) + " ";
}
else
{
my_file= replace_string(my_file,"wtypeItext",	"0");
}
if (random(is)==0)
{
fhtest=basefhtest+random(5+lev);
my_file= replace_string(my_file,"wtypeJtext",	fhtest+"");
strnf +=TYPE3[9]["TYPE1"]+":"+ w_power(fhtest) + " ";
}
else
{
my_file= replace_string(my_file,"wtypeJtext",	"0");
}

if (random(is)==0)
{
fhtest=basefhtest+random(5+lev);
my_file= replace_string(my_file,"wtypeKtext",	fhtest+"");
strnf +=TYPE3[10]["TYPE1"]+":"+ w_power(fhtest) + " ";
}
else
{
my_file= replace_string(my_file,"wtypeKtext",	"0");
}

if (random(is)==0 )
{
fhtest=basefhtest+random(5+lev);
my_file= replace_string(my_file,"wtypeLtext",	fhtest+"");  
strnf +=TYPE3[11]["TYPE1"]+":"+ w_power(fhtest) +	" ";
}
else
{
my_file= replace_string(my_file,"wtypeLtext",	"0");
}

	if( stringp(weaponlong) )
		str = weaponlong;
	str += "����һ"+type["TYPE4"]+"��" + s_good(rigidity) + "��Ӳ��";

	switch(material){
		case "hantie":	str += HIC"���꺮����"NOR; break;
		case "xuantie":	str += WHT"����"NOR; break;
case "shentie":	str += RED"��������"NOR; break;
case "jintie":	str += HIY"����"NOR; break;				
case "ruanying":	str += HIW"����"NOR; break;
case "liuhuashi":	str += RED"����ʯ"NOR; break;				
case "lushi":	str += HIG"��ʯ"NOR; break;	
case "ruantie":	str += YEL"����"NOR; break;	
case "shengtie":	str += YEL"����"NOR; break;	
case "qingtong":	str += GRN"��ͭ"NOR; break;				
		default: str +=	"����";	break;
	}
	w = weighttext;
	str +=	"�Ƴɣ���"+sprintf("%s", chinese_number(w/500)+"��"+chinese_number((w%500)/50)+"��"+chinese_number((w%50)/5)+"Ǯ")+"��"+weaponname+"��\n";

	//mm = w_mp;
  //weili;
	
	str += "�ۺ�����"	+ s_good2(lev)+" ������"	+ ( s_good(rigidity)+"������" ) + "����"+ s_power(weilitext) + "��������";
if (strnf!="")
{
	str += "\n������˼����ŷ��ţ�\n"
		+strnf;
}
		str += "\n���滹����һЩ���֣�\n"
		+strn+"\n";




		

  my_file= replace_string(my_file,"WEAPONTYPE",type["TYPE1"]);
  my_file= replace_string(my_file,"TYPEDM",type["TYPE2"]);

  my_file= replace_string(my_file,"WEAPON_SWORD",weaponname+"��");
  
  my_file= replace_string(my_file,"WEAPON_ID",weaponid);
	my_file= replace_string(my_file,"IDTYPE",type["TYPE2"]);
	my_file= replace_string(my_file,"LONG_TITLE",str);
  my_file= replace_string(my_file,"unittext",type["TYPE4"]);


// now we need to write out this file!
// do NOT change this one!
	//write_file("/p/residence/weapon/"+name+".o",my_file,1);
	
// change this one to write_file2
//rm("/p/residence/weapon/"+name+".c");
	
name="W"+type["TYPE2"]+sl;
        write_file("/p/item/"+path+"/"+name+".c",my_file,1);
//write("��������ɹ�����\n");
//if (!wizardp(me))
//{

//}
//message_vision(HIR "�������ɳɹ�!���ļ���Ϊ:"+"/p/residence/weapon/"+name+".c"+"\n" NOR, me);


//newob->move(me);
       return 1;
}



int armormake(int sl,int ty,int lv,int zl,string path)
{
	string weaponname,weaponid,weaponlong,str,material,strn,strnf,material2;
	object *user, newob,me;
	object *inv;
	int i,rigidity,w;
  //object conc;
	//object env;
	//string this_file;
	string my_file;
	string file;
	string name;
	//string c_name,o_name;
  mapping type;
  int weighttext;
  int valuetext;
  int weilitext,weilijc;
  int sharpness;
  int gifttext;
  int sztest;
  int fhtest;
  int skilllevtext;
  int is,lev;
  int basegifttext,basesztest,basefhtest,yushi,color;

  me=this_player();

  color=random(13);


seteuid(getuid());

//	if( wiz_status != "(admin)" && wiz_status != "(arch)" )
//		return notify_fail("ֻ�� (arch) ���ϵ���ʦ����ʹ��!\n");


	name = (string)me->query("id")+"_a"+me->query_temp("item/dzwz");



my_file = read_file("/obj/ritem/ARMOR.o");


//������0-9
type = TYPE2[ty];

//�ȼ�����1-6
lev = lv;
//���Ͼ��ȼ���
//��ʯ����
yushi=lv/2+2;



//���ϲ���
//if (lv>3) lv=lv+random(4);

	switch(lv){
		case 1:	material="qingtong"; break;
		case 2:	material="shengtie"; break;
case 3:	material="ruantie"; break;
case 4:	material="lushi"; break;				
case 5:	material="liuhuashi"; break;
case 6:	material="ruanying"; break;				
case 7:	 material="jintie"; break;	
case 8:	material="shentie";	 break;	
case 9:	material="xuantie";	 break;	
case 10:	material="hantie";	 break;	
		default: material="qingtong";	break;
	}

	switch(lv){
		case 1:	material2="mianhua"; break;
		case 2:	material2="yama"; break;
case 3:	material2="dama"; break;
case 4:	material2="zhuma"; break;				
case 5:	material2="cansi"; break;
case 6:	material2="mumianhua"; break;				
case 7:	 material2="yucansi"; break;	
case 8:	material2="bingcansi";	 break;	
case 9:	material2="tiancansi";	 break;	
case 10:	material2="longcansi";	 break;	
		
		default: material="mianhua";	break;
	}



//��ʯ���ȼ���

//�����ɲ��Ͼ���
weighttext=1000+random(15000);




//�����ɲ��Ͼ���

material=me->query_temp("item/kuangshi");
	switch(material){
		case "hantie":	weighttext=2000+random(5000); break;
		case "xuantie":	weighttext=1800+random(5000); break;
case "shentie":	weighttext=1500+random(5000); break;
case "jintie":	weighttext=1300+random(6000); break;				
case "ruanying":	weighttext=1200+random(6000); break;
case "liuhuashi":	weighttext=1000+random(5000);; break;				
case "lushi":	weighttext=950+random(4000); break;	
case "ruantie":	weighttext=900+random(3000); break;	
case "shengtie":	weighttext=800+random(2000); break;	
case "qingtong":	weighttext=700+random(1000); break;				
		default: weighttext=600+random(1000);	break;
	}

if (type["TYPE2"]!="cloth" && type["TYPE2"]!="shield" ) weighttext=weighttext/2+1;
	
//������������
	switch(material2){
		case "longcansi": weilijc=160;break;		
		case "tiancansi": weilijc=120; break;
		case "bingcansi": weilijc=100; break;
		case "yucansi":   weilijc=90; break;
		case "mumianhua": weilijc=80; break;
		case "cansi":     weilijc=70; break;
		case "zhuma":     weilijc=60; break;
		case "dama":      weilijc=50; break;
		case "yama":      weilijc=40; break;
		case "mianhua":   weilijc=20; break;
		default: weilijc=10;	break;
	}


//write(lev+"");
//return 1;
if (lev==6)
{
		i = zl;
		weaponname	= keys(Special_Class)[i];
    weaponid	=  Special_Class[weaponname]["id"] + " " + type["TYPE2"];
    weaponlong = Special_Class[weaponname]["long2"];
		weaponname	= keys(Special_Class)[i] + "֮" + type["TYPE3"]+NOR;
//����ѧϰ������
i=random(sizeof(BOOK1));		
//Ӳ��
rigidity=6+random(18);
//��ֵ
valuetext=6000*lev;
//����
weilitext=60*lev+weilijc;
//����
sharpness=3*lev+random(10);
//�������Ը���
basegifttext=6*lev;
//��������
basesztest=6*lev;
//��������
basefhtest=6;
//����ѧϰ�书�ĵȼ�
skilllevtext=80*lev;
//���ֵĻ���
is=5;
}
else
if (lev==5)
{
		i = zl;
		weaponname	= keys(Super_Class)[i];
    weaponid	=  Super_Class[weaponname]["id"] + " " + type["TYPE2"];
    weaponlong = Super_Class[weaponname]["long2"];
		weaponname	= keys(Super_Class)[i] + "֮" + type["TYPE3"]+NOR;
//����ѧϰ������
i=random(sizeof(BOOK1));		
//Ӳ��
rigidity=5+random(18);
//��ֵ
valuetext=5000*lev;
//����
weilitext=50*lev+weilijc;
//����
sharpness=3*lev+random(8);
//�������Ը���
basegifttext=5*lev;
//��������
basesztest=5*lev;
//��������
basefhtest=5;
//����ѧϰ�书�ĵȼ�
skilllevtext=60*lev;
//���ֵĻ���
is=6;

}		
else
if (lev==4)
{
		i = zl;
		weaponname	= keys(Great_Class)[i];
    weaponid	=  Great_Class[keys(Great_Class)[i]] + " " + type["TYPE2"];
    weaponlong = keys(Great_Class)[i] + "֮" + type["TYPE3"]+NOR;
		weaponname	= keys(Great_Class)[i] + "֮" + type["TYPE3"]+NOR;
//����ѧϰ������
i=random(sizeof(BOOK1));		
//Ӳ��
rigidity=4+random(18);
//��ֵ
valuetext=4000*lev;
//����
weilitext=40*lev+weilijc;
//����
sharpness=3*lev+random(7);
//�������Ը���
basegifttext=4*lev;
//��������
basesztest=4*lev;
//��������
basefhtest=4;
//����ѧϰ�书�ĵȼ�
skilllevtext=80*lev;
//���ֵĻ���
is=7;
}		
else
if (lev==3)
{
		i = zl;
		weaponname	= G_3_class[i];
    weaponid	=  "good " + type["TYPE2"];
    weaponlong = G_3_class[i] + "֮" + type["TYPE3"]+NOR;
		weaponname	= order[color] +G_3_class[i] + "֮" + type["TYPE3"]+NOR;
//����ѧϰ������
i=random(sizeof(BOOK1));		
//Ӳ��
rigidity=3+random(18);
//��ֵ
valuetext=3000*lev;
//����
weilitext=30*lev+weilijc;
//����
sharpness=3*lev+random(5);
//�������Ը���
basegifttext=3*lev;
//��������
basesztest=3*lev;
//��������
basefhtest=3;
//����ѧϰ�书�ĵȼ�
skilllevtext=80*lev;
//���ֵĻ���
is=8;

}		
else
if (lev==2)
{
		i = zl;
		weaponname	= G_4_class[i];
    weaponid	=  "general " + type["TYPE2"];
    weaponlong = G_4_class[i] + "֮" + type["TYPE3"]+NOR;
		weaponname	= order[color] +G_4_class[i] + "֮" + type["TYPE3"]+NOR;
//����ѧϰ������
i=random(sizeof(BOOK1));		
//Ӳ��
rigidity=2+random(12);
//��ֵ
valuetext=2000;
//����
weilitext=20*lev+weilijc;
//����
sharpness=3+random(4);
//�������Ը���
basegifttext=2;
//��������
basesztest=2;
//��������
basefhtest=2;
//����ѧϰ�书�ĵȼ�
skilllevtext=120;
//���ֵĻ���
is=9;

}
else
if (lev==1)
{
		i = zl;
		weaponname	= G_5_class[i];
    weaponid	=  "bad " + type["TYPE2"];
    weaponlong = G_5_class[i] + "֮" + type["TYPE3"]+NOR;
		weaponname	= order[color] +G_5_class[i] + "֮" + type["TYPE3"]+NOR;
//����ѧϰ������
i=random(sizeof(BOOK1));		
//Ӳ��
rigidity=1+random(6);
//��ֵ
valuetext=2000;
//����
weilitext=20+weilijc;
//����
sharpness=1+random(3);
//�������Ը���
basegifttext=1;
//��������
basesztest=1;
//��������
basefhtest=1;
//����ѧϰ�书�ĵȼ�
skilllevtext=50;
//���ֵĻ���
is=10;
}
//is=2
//����Ҫ���ߣ�������Ч���ܼ���
if (type["TYPE2"]!="cloth") is=is+5;
//is=1;

is=is+5-yushi;

if (yushi==6 && is>6) is=6;
if (yushi==5 && is>7) is=7;
if (yushi==4 && is>8) is=8;
if (yushi==3 && is>9) is=9;


//write(yushi+"A");
//write(is+"B");
/*  if (type["TYPE2"]=="throwing" )
{
    //my_file= replace_string(my_file,"weaponamount","1");
}
else
{
	//my_file= replace_string(my_file,"set_amount(weaponamount);","");
}*/






//my_file= replace_string(my_file,"materialtext","default");
if (!my_file) my_file = read_file("/obj/ritem/armor.o");
if (!my_file) my_file = read_file("/obj/ritem/ARMOR.o");
if (!my_file) my_file = read_file("/obj/ritem/armor.o");

my_file= replace_string(my_file,"sharpnesstext",""+sharpness+"");
strn="��Ӳ:"+w_power(sharpness)+" ";


my_file= replace_string(my_file,"weighttext",weighttext+"");


	my_file= replace_string(my_file,"ownertext",	me->query("id"));
	my_file= replace_string(my_file,"ownernametext",	me->query("name"));
  my_file= replace_string(my_file,"valuetext",	valuetext+"");
  //my_file= replace_string(my_file,"weilitext",	weilitext+"");

if (random(is)==0)
{
gifttext=basegifttext+random(lev*6);
  my_file= replace_string(my_file,"inttext",	gifttext+"");
strn +="����:"+w_power2(gifttext)+" ";
}
else
{
  my_file= replace_string(my_file,"inttext","0");		
}

if (random(is)==0)
{
gifttext=basegifttext+random(lev+6);
  my_file= replace_string(my_file,"strtext",	gifttext+"");
strn +="����:"+w_power2(gifttext)+" ";
}
else
{
  my_file= replace_string(my_file,"strtext","0");
}

if (random(is)==0)
{
gifttext=basegifttext+random(lev+6);
  my_file= replace_string(my_file,"kartext",	gifttext+"");
strn +="��Դ:"+w_power2(gifttext)+" "+"\n";
}
else
{
  my_file= replace_string(my_file,"kartext",	"0");
}

if (random(is)==0)
{
gifttext=basegifttext+random(lev+6);
  my_file= replace_string(my_file,"pertext",	gifttext+"");
strn +="����:"+w_power2(gifttext)+" ";
}
else
{
my_file= replace_string(my_file,"pertext",	"0");
}

if (random(is)==0)
{
gifttext=basegifttext+random(lev+6);
  my_file= replace_string(my_file,"dextext",	gifttext+"");
strn +="��Ԩ:"+w_power2(gifttext)+" ";
}
else
{
my_file= replace_string(my_file,"dextext",	"0");
}

if (random(is)==0)
{
gifttext=basegifttext+random(lev+6);
  my_file= replace_string(my_file,"context",	gifttext+"");      
strn +="����:"+w_power2(gifttext)+" ";
}
else
{
my_file= replace_string(my_file,"context",	"0");      
}
//write(lev+" ");
//write(weilitext+" ");
//���Ƿ�װΪ1/3
if (type["TYPE2"]!="cloth") weilitext=weilitext/3+1;
//write(type["TYPE2"]);
//write(weilitext+" ");
//return 1;
//if (random(is)==0)
//{
if (type["TYPE2"]=="cloth" || type["TYPE2"]=="shield") weilitext=weilitext+180;
sztest=basesztest+random(lev*10);
my_file= replace_string(my_file,"armortext",	weilitext+"");  
strn +="����:"+w_power2(sztest)+" "+"\n";
//}
//else
//{
//my_file= replace_string(my_file,"armortext",	"0");      
//}

if (random(is)==0)
{
sztest=basesztest+random(lev*10);
my_file= replace_string(my_file,"defensetext",	sztest+""); 
strn +="����:"+w_power2(sztest)+" ";
}
else
{
my_file= replace_string(my_file,"defensetext",	"0");      
}

if (random(is)==0)
{
sztest=basesztest+random(lev*10);
my_file= replace_string(my_file,"dodgetext",	sztest+"");  
strn +="��ʯ:"+w_power2(sztest)+" ";
}
else
{
my_file= replace_string(my_file,"dodgetext",	"0");      
}

if (random(is)==0)
{
sztest=basesztest+random(lev*10);
my_file= replace_string(my_file,"parrytest",	sztest+"");  
strn +="��ʯ:"+w_power2(sztest)+" ";
}
else
{
my_file= replace_string(my_file,"parrytest",	"0");      
}

if (random(is)==0)
{
sztest=basesztest+random(lev*10);
my_file= replace_string(my_file,"attacktest",	sztest+"");  
strn +="����:"+w_power2(sztest)+" "+"\n";
}
else
{
my_file= replace_string(my_file,"attacktest",	"0");      
}

if (random(is)==0)
{ 
sztest=basesztest+random(lev*10);
my_file= replace_string(my_file,"neilitext",	sztest+"");  
strn +="����:"+w_power2(sztest)+" ";
}
else
{
my_file= replace_string(my_file,"neilitext",	"0");      
}

if (random(is)==0)
{ 
sztest=basesztest+random(lev*10);
my_file= replace_string(my_file,"qitext",	sztest+"");  
strn +="����:"+w_power2(sztest)+" ";
}
else
{
my_file= replace_string(my_file,"qitext",	"0");      
}

if (random(is)==0)
{ 
sztest=basesztest+random(lev*10);
my_file= replace_string(my_file,"jingtext",	sztest+"");  
my_file= replace_string(my_file,"jinglitext",	sztest+"");  
strn +="����:"+w_power2(sztest)+" ";
}
else
{
my_file= replace_string(my_file,"jingtext",	"0");   
my_file= replace_string(my_file,"jinglitext",	"0");      
}

if (type["TYPE2"]=="hands")
{
sztest=basesztest*2+(lev*20)+100;
my_file= replace_string(my_file,"damagetext",	sztest+"");  
strn +="����:"+w_power2(basesztest+(lev*5))+" ";
}
else if (random(is)==0)
{
sztest=basesztest+random(lev*10);
my_file= replace_string(my_file,"damagetext",	sztest+"");  
strn +="����:"+w_power2(sztest)+" ";
}
else
{
my_file= replace_string(my_file,"damagetext",	"0");      
}

my_file= replace_string(my_file,"skillnametext",	BOOK1[i]["TYPE2"]);  
my_file= replace_string(my_file,"skilllevtext",	skilllevtext+""); 


strnf="";
if (random(is)==0)
{
fhtest=basefhtest+random(5+lev);
my_file= replace_string(my_file,"wtypeAtext",	fhtest+"");
strnf=TYPE3[0]["TYPE1"]+":"+ w_power(fhtest) + " ";
}
else
{
my_file= replace_string(my_file,"wtypeAtext",	"0");
}

if (random(is)==0)
{
fhtest=basefhtest+random(5+lev);
my_file= replace_string(my_file,"wtypeBtext",	fhtest+"");
strnf +=TYPE3[1]["TYPE1"]+":"+ w_power(fhtest) + " ";
}
else
{
my_file= replace_string(my_file,"wtypeBtext",	"0");
}

if (random(is)==0)
{
fhtest=basefhtest+random(5+lev);
my_file= replace_string(my_file,"wtypeCtext",	fhtest+"");
strnf +=TYPE3[2]["TYPE1"]+":"+ w_power(fhtest) + " ";
}
else
{
my_file= replace_string(my_file,"wtypeCtext",	"0");
}

if (random(is)==0)
{
fhtest=basefhtest+random(5+lev);
my_file= replace_string(my_file,"wtypeDtext",	fhtest+"");
strnf +=TYPE3[3]["TYPE1"]+":"+ w_power(fhtest) + " ";
}
else
{
my_file= replace_string(my_file,"wtypeDtext",	"0");
}

if (random(is)==0)
{
fhtest=basefhtest+random(5+lev);
my_file= replace_string(my_file,"wtypeEtext",	fhtest+"");
strnf +=TYPE3[4]["TYPE1"]+":"+ w_power(fhtest) + " ";
}
else
{
my_file= replace_string(my_file,"wtypeEtext",	"0");
}

if (random(is)==0)
{
fhtest=basefhtest+random(5+lev);
my_file= replace_string(my_file,"wtypeFtext",	fhtest+"");
strnf +=TYPE3[5]["TYPE1"]+":"+ w_power(fhtest) + " \n";
}
else
{
my_file= replace_string(my_file,"wtypeFtext",	"0");
}

if (random(is)==0)
{
fhtest=basefhtest+random(5+lev);
my_file= replace_string(my_file,"wtypeGtext",	fhtest+"");
strnf +=TYPE3[6]["TYPE1"]+":"+ w_power(fhtest) + " ";
}
else
{
my_file= replace_string(my_file,"wtypeGtext",	"0");
}

if (random(is)==0)
{
fhtest=basefhtest+random(5+lev);
my_file= replace_string(my_file,"wtypeHtext",	fhtest+"");
strnf +=TYPE3[7]["TYPE1"]+":"+ w_power(fhtest) + " ";
}
else
{
my_file= replace_string(my_file,"wtypeHtext",	"0");
}

if (random(is)==0)
{
fhtest=basefhtest+random(5+lev);
my_file= replace_string(my_file,"wtypeItext",	fhtest+"");
strnf +=TYPE3[8]["TYPE1"]+":"+ w_power(fhtest) + " ";
}
else
{
my_file= replace_string(my_file,"wtypeItext",	"0");
}
if (random(is)==0)
{
fhtest=basefhtest+random(5+lev);
my_file= replace_string(my_file,"wtypeJtext",	fhtest+"");
strnf +=TYPE3[9]["TYPE1"]+":"+ w_power(fhtest) + " ";
}
else
{
my_file= replace_string(my_file,"wtypeJtext",	"0");
}

if (random(is)==0)
{
fhtest=basefhtest+random(5+lev);
my_file= replace_string(my_file,"wtypeKtext",	fhtest+"");
strnf +=TYPE3[10]["TYPE1"]+":"+ w_power(fhtest) + " ";
}
else
{
my_file= replace_string(my_file,"wtypeKtext",	"0");
}

if (random(is)==0 )
{
fhtest=basefhtest+random(5+lev);
my_file= replace_string(my_file,"wtypeLtext",	fhtest+"");  
strnf +=TYPE3[11]["TYPE1"]+":"+ w_power(fhtest) +	" ";
}
else
{
my_file= replace_string(my_file,"wtypeLtext",	"0");
}

	if( stringp(weaponlong) )
		str = weaponlong;
	str += "����һ"+type["TYPE4"]+"��" + s_good(rigidity) + "��Ӳ��";

	switch(material){
		case "hantie":	str += HIC"���꺮����"NOR; break;
		case "xuantie":	str += WHT"����"NOR; break;
case "shentie":	str += RED"��������"NOR; break;
case "jintie":	str += HIY"����"NOR; break;				
case "ruanying":	str += HIW"����"NOR; break;
case "liuhuashi":	str += RED"����ʯ"NOR; break;				
case "lushi":	str += HIG"��ʯ"NOR; break;	
case "ruantie":	str += YEL"����"NOR; break;	
case "shengtie":	str += YEL"����"NOR; break;	
case "qingtong":	str += GRN"��ͭ"NOR; break;				
		default: str +=	"����";	break;
	}
	
	str += "����";
	switch(material2){
		case "longcansi": str += HIY"�����˿"NOR;break;		
		case "tiancansi": str += WHT"���˿"NOR; break;
		case "bingcansi": str += HIW"����˿"NOR; break;
		case "yucansi":   str += GRN"���˿"NOR; break;
		case "mumianhua": str += HIY"ľ�޻�"NOR; break;
		case "cansi":     str += HIW"��˿"NOR; break;
		case "zhuma":     str += HIY"����"NOR; break;
		case "dama":      str += YEL"����"NOR; break;
		case "yama":      str += YEL"����"NOR; break;
		case "mianhua":   str += HIW"�޻�"NOR; break;
		default: str +=	"����";	break;
	}
	
	w = weighttext;
	str +=	"�Ƴɣ���"+sprintf("%s", chinese_number(w/500)+"��"+chinese_number((w%500)/50)+"��"+chinese_number((w%50)/5)+"Ǯ")+"��"+weaponname+"��\n";

	//mm = w_mp;
  //weili;
	
	str += "�ۺ�����"	+ s_good2(lev)+" ������"	+ ( s_good(rigidity)+"��̣�" ) + "����"+ s_power(weilitext) + "�ķ�������";
if (strnf!="")
{
	str += "\n������˼����ŷ��ţ�\n"
		+strnf;
}
		str += "\n���滹����һЩ���֣�\n"
		+strn+"\n";





		

  my_file= replace_string(my_file,"WEAPONTYPE",type["TYPE1"]);
  my_file= replace_string(my_file,"TYPEDM",type["TYPE2"]);

  my_file= replace_string(my_file,"WEAPON_SWORD",weaponname+"��");
  my_file= replace_string(my_file,"WEAPON_ID",weaponid);
	my_file= replace_string(my_file,"IDTYPE",type["TYPE2"]);
	my_file= replace_string(my_file,"LONG_TITLE",str);
  my_file= replace_string(my_file,"unittext",type["TYPE4"]);


// now we need to write out this file!
// do NOT change this one!
// change this one to write_file2
//rm("/p/residence/weapon/"+name+".c");

		       name="A"+type["TYPE2"]+sl;
        write_file("/p/item/"+path+"/"+name+".c",my_file,1);

//newob->move(me);
       return 1;
}