#include <ansi.h> 
#include <armor.h>

inherit CLOTH;

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
	      set_name("[35m½ğ²õ[2;37;0m", ({ "good cloth", "cloth" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "¼ş");
		set("long", @LONG
òÔÁúÖ®·ş×°[2;37;0mÕâÊÇÒ»¼şÓÉ·Ç³£¼áÓ²µÄ[1;37mÈíÒø[2;37;0m¼ÓÉÏ[1;33mÄ¾ÃŞ»¨[2;37;0mÖÆ³É£¬ÖØÎå½ïÁãÁ½ÁùÇ®µÄ[35mòÔÁúÖ®·ş×°[2;37;0m¡£
×ÛºÏÆÀ¼Û[1;34m¾ÙÊÀº±¼û[2;37;0m ¿´ÆğÀ´·Ç³£¼á¹Ì£¬¾ßÓĞ[32mË®×¼ÒÔÉÏ[2;37;0mµÄ·À»¤Á¦£¡
ÉÏÃæ¿ÌÁË¼¸¸ö¹Å·ûºÅ£º
[40mµØ[2;37;0m:[1;32mÄ§Íõ[2;37;0m [1;36mÈË[2;37;0m:[31m¾«ÖÂ[2;37;0m [36mÄ¾[2;37;0m:[1;32mÄ§Íõ[2;37;0m [1;35m·ç[2;37;0m:[33mºÜ¸ß[2;37;0m 

ÉÏÃæ»¹¿ÌÁËÒ»Ğ©·û×Ö£º
¼áÓ²:[1;32mÄ§Íõ[2;37;0m ÌìÓî:[33mÒ»°ã[2;37;0m ÇÉÖÆ:[36m²»´í[2;37;0m 
ÉÁµç:[34mÏ¸Ëé[2;37;0m 
ÖÜÌì:[32m´Ö²Ú[2;37;0m ³¤Éú:[32m´Ö²Ú[2;37;0m 
ÒÔ¼°Ò»ÅÅ¹Å×­×Ö¡¾ [1;32mº®±ù[2;37;0m ¡¿¡£ºÍÒ»Ğ©¡¾ [1;32m´¸·¨[2;37;0m ¡¿µÄ¼¼ÇÉ¡£

LONG
);
			set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "ordcn");
		set("ownername", "º®±ù");
		set("value", 9000);
		set("armor_prop/intelligence",0);
		set("armor_prop/strength",10);
		set("armor_prop/karey",0);
		set("armor_prop/percao",0);
		set("armor_prop/dexerity",0);
		set("armor_prop/constitution",0);
    set("armor_prop/dodge", 0);
    set("armor_prop/parry", 0);
    set("armor_prop/attack", 29);


    set("armor_prop/armor", 270);
    set("armor_prop/defense", 0);
    
    set("armor_prop/neili", 37);
    set("armor_prop/qi", 31);
    set("armor_prop/jing", 0);
    set("armor_prop/jingli", 0);
    set("armor_prop/damage", 0);

    set("wtypeA",0);
    set("wtypeB",9);
    set("wtypeC",0);
    set("wtypeD",0);
    set("wtypeE",0);
    set("wtypeF",4);
    set("wtypeG",0);
    set("wtypeH",0);
    set("wtypeI",0);
    set("wtypeJ",9);
    set("wtypeK",6);
    set("wtypeL",0);
    
    
                set("skill", ([
                        "name": "hammer",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 240,              
                ]) );		


		set("material", "default");
    set("sharpness", 9);
        }
        setup();
}

int query_autoload() { return 1; }

#include "/obj/armorzy.h";