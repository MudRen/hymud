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
	      set_name("[1;33m������[2;37;0m", ({ "zhanlu hands", "hands" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
		set("long", @LONG
[31mտ¬��������������Ӳ���ھ���������ǧ�������
[2;37;0m����һ�����ޱȼ�Ӳ��[1;36m���꺮����[2;37;0m����[1;33m�����˿[2;37;0m�Ƴɣ����Ľ�������Ǯ��[31mտ¬֮����[2;37;0m��
�ۺ�����[35m�������[2;37;0m �������ޱȼ�̣�����[32mˮ׼����[2;37;0m�ķ�������
������˼����ŷ��ţ�
[40m��[2;37;0m:[1;33m��ʥ[2;37;0m [32mˮ[2;37;0m:[1;31m��˫[2;37;0m [33m��[2;37;0m:[31m����[2;37;0m [1;35m��[2;37;0m:[1;35m����[2;37;0m 
[1;37m��[2;37;0m:[1;31m����[2;37;0m 
���滹����һЩ���֣�
��Ӳ:[1;33m����[2;37;0m ��Ԩ:[33m�ܸ�[2;37;0m ����:[1;34m����[2;37;0m 
��ʯ:[1;34m����[2;37;0m ����:[1;36m����[2;37;0m ����:[1;36m����[2;37;0m ����:[33m�ܸ�[2;37;0m 
�Լ�һ�Ź�׭�֡� [1;32m�ɴ�[2;37;0m ������һЩ�� [1;32m�ȷ�[2;37;0m ���ļ��ɡ�

LONG
);
			set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "cjs");
		set("ownername", "�ɴ�");
		set("value", 36000);
		set("armor_prop/intelligence",48);
		set("armor_prop/strength",56);
		set("armor_prop/karey",56);
		set("armor_prop/percao",48);
		set("armor_prop/dexerity",45);
		set("armor_prop/constitution",40);
    set("armor_prop/dodge", 56);
    set("armor_prop/parry", 80);
    set("armor_prop/attack", 56);


    set("armor_prop/armor", 335);
    set("armor_prop/defense", 56);
    
    set("armor_prop/neili", 64);
    set("armor_prop/qi", 71);
    set("armor_prop/jing", 75);
    set("armor_prop/jingli", 75);
    set("armor_prop/damage", 1204);

    set("wtypeA",7);
    set("wtypeB",0);
    set("wtypeC",12);
    set("wtypeD",9);
    set("wtypeE",6);
    set("wtypeF",11);
    set("wtypeG",15);
    set("wtypeH",7);
    set("wtypeI",7);
    set("wtypeJ",10);
    set("wtypeK",6);
    set("wtypeL",6);
    
    
                set("skill", ([
                        "name": "leg",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 480,              
                ]) );		


		set("material", "default");
    set("sharpness", 24);
        }
        setup();
}

int query_autoload() { return 1; }

#include "/obj/armorzy.h";