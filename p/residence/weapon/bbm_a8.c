#include <ansi.h> 
#include <armor.h>

inherit SURCOAT;

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
"anqi_poison",
"nx_poison",
"chilian_poison",
"yufeng_poison",
"insect_poison",
"xscold_poison",
});

string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});  
void create()
{
	      set_name("[1;32m�ù�������[2;37;0m", ({ "taibai surcoat", "surcoat" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
		set("long", @LONG
[1;37m
		�Կ��Ϻ�ӧ  �⹳˪ѩ��		�����հ���  ��������
		ʮ��ɱһ��  ǧ�ﲻ����		���˷���ȥ  ���������
		�й�������  �ѽ�ϥǰ��		���ˡ��캥  ����Ȱ����
		������Ȼŵ  ������Ϊ��		�ۻ�������  ����������
		���Իӽ��  ��������		ǧ���׳ʿ  ���մ�����
		����������  ��������Ӣ		˭�������  ����̫����
[2;37;0m����һ�����ޱȼ�Ӳ��[31m��������[2;37;0m����[1;37m����˿[2;37;0m�Ƴɣ������������Ǯ��[1;37m̫��֮�Ǵ�[2;37;0m��
�ۺ�����[1;36m��˫�޶�[2;37;0m �������ޱȼ�̣�����[34m����[2;37;0m�ķ�������
������˼����ŷ��ţ�
[1;33m��[2;37;0m:[1;35m����[2;37;0m [36mľ[2;37;0m:[1;34m����[2;37;0m [1;35m��[2;37;0m:[31m����[2;37;0m 
[1;37m��[2;37;0m:[1;34m����[2;37;0m [1;34m��[2;37;0m:[1;32mħ��[2;37;0m 
���滹����һЩ���֣�
��Ӳ:[1;33m����[2;37;0m ����:[35m��׼[2;37;0m 
��ʯ:[32m�ֲ�[2;37;0m ����:[32m�ֲ�[2;37;0m 
����:[35m��׼[2;37;0m ����:[31m����[2;37;0m 
�Լ�һ�Ź�׭�֡� [1;32m����[2;37;0m ������һЩ�� [1;32m����[2;37;0m ���ļ��ɡ�

LONG
);
			set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "bbm");
		set("ownername", "����");
		set("value", 25000);
		set("armor_prop/intelligence",0);
		set("armor_prop/strength",0);
		set("armor_prop/karey",0);
		set("armor_prop/percao",0);
		set("armor_prop/dexerity",40);
		set("armor_prop/constitution",0);
    set("armor_prop/dodge", 33);
    set("armor_prop/parry", 0);
    set("armor_prop/attack", 33);


    set("armor_prop/armor", 216);
    set("armor_prop/defense", 32);
    
    set("armor_prop/neili", 32);
    set("armor_prop/qi", 59);
    set("armor_prop/jing", 66);
    set("armor_prop/jingli", 66);
    set("armor_prop/damage", 82);

    set("wtypeA",11);
    set("wtypeB",8);
    set("wtypeC",4);
    set("wtypeD",0);
    set("wtypeE",4);
    set("wtypeF",6);
    set("wtypeG",8);
    set("wtypeH",9);
    set("wtypeI",0);
    set("wtypeJ",0);
    set("wtypeK",0);
    set("wtypeL",3);
    
    
                set("skill", ([
                        "name": "club",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 300,              
                ]) );		


		set("material", "default");
    set("sharpness", 16);
        }
        setup();
}

int query_autoload() { return 1; }

#include "/obj/armorzy.h";