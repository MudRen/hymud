#include <ansi.h> 
#include <armor.h>

inherit HANDS;

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
	      set_name("[34m��ڤ����[2;37;0m", ({ "zhanlu hands", "hands" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
		set("long", @LONG
[31mտ¬��������������Ӳ���ھ���������ǧ�������
[2;37;0m����һ�����ޱȼ�Ӳ��[1;36m���꺮����[2;37;0m����[1;33m�����˿[2;37;0m�Ƴɣ������������Ǯ��[31mտ¬֮����[2;37;0m��
�ۺ�����[35m�������[2;37;0m �������ޱȼ�̣�����[32mˮ׼����[2;37;0m�ķ�������
������˼����ŷ��ţ�
[1;36m��[2;37;0m:[1;33m����[2;37;0m [33m��[2;37;0m:[1;31m��˫[2;37;0m [1;35m��[2;37;0m:[1;31m����[2;37;0m 
[1;37m��[2;37;0m:[1;31m����[2;37;0m [1;34m��[2;37;0m:[1;31m����[2;37;0m 
���滹����һЩ���֣�
��Ӳ:[1;33m����[2;37;0m ����:[33m�ܸ�[2;37;0m ����:[1;32mħ��[2;37;0m 
����:[31m����[2;37;0m ��ʯ:[31m����[2;37;0m ����:[35m��׼[2;37;0m ����:[1;34m����[2;37;0m ����:[33m�ܸ�[2;37;0m 
�Լ�һ�Ź�׭�֡� [1;32m��ӣ[2;37;0m ������һЩ�� [1;32mȭ��[2;37;0m ���ļ��ɡ�

LONG
);
			set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "kamuls");
		set("ownername", "��ӣ");
		set("value", 36000);
		set("armor_prop/intelligence",0);
		set("armor_prop/strength",0);
		set("armor_prop/karey",0);
		set("armor_prop/percao",0);
		set("armor_prop/dexerity",0);
		set("armor_prop/constitution",47);
    set("armor_prop/dodge", 61);
    set("armor_prop/parry", 0);
    set("armor_prop/attack", 0);


    set("armor_prop/armor", 252);
    set("armor_prop/defense", 66);
    
    set("armor_prop/neili", 58);
    set("armor_prop/qi", 89);
    set("armor_prop/jing", 40);
    set("armor_prop/jingli", 24);
    set("armor_prop/damage", 1121);

    set("wtypeA",0);
    set("wtypeB",0);
    set("wtypeC",0);
    set("wtypeD",2);
    set("wtypeE",12);
    set("wtypeF",15);
    set("wtypeG",15);
    set("wtypeH",15);
    set("wtypeI",0);
    set("wtypeJ",0);
    set("wtypeK",16);
    set("wtypeL",3);
    
    
                set("skill", ([
                        "name": "cuff",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 480,              
                ]) );		


		set("material", "default");
    set("sharpness", 23);
        }
        setup();
}

int query_autoload() { return 1; }

#include "/obj/armorzy.h";