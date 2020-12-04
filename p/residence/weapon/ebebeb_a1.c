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
	      set_name("[1;37mÎŞÓ°¼×[2;37;0m", ({ "good cloth", "cloth" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "¼ş");
		set("long", @LONG
»¨ÎÆÖ®·ş×°[2;37;0mÕâÊÇÒ»¼şÓÉÎŞ±È¼áÓ²µÄ[1;37mÈíÒø[2;37;0m¼ÓÉÏ[1;33mÄ¾ÃŞ»¨[2;37;0mÖÆ³É£¬ÖØ°Ë½ïÎåÁ½¾ÅÇ®µÄ[1;37m»¨ÎÆÖ®·ş×°[2;37;0m¡£
×ÛºÏÆÀ¼Û[1;34m¾ÙÊÀº±¼û[2;37;0m ¿´ÆğÀ´ÎŞ±È¼á¹Ì£¬¾ßÓĞ[32mË®×¼ÒÔÉÏ[2;37;0mµÄ·À»¤Á¦£¡
ÉÏÃæ¿ÌÁË¼¸¸ö¹Å·ûºÅ£º
[1;31mÄ§[2;37;0m:[1;34m¾ÙÊÀ[2;37;0m 
ÉÏÃæ»¹¿ÌÁËÒ»Ğ©·û×Ö£º
¼áÓ²:[1;33mÌìÊ¥[2;37;0m ¸£Ô´:[33mÒ»°ã[2;37;0m 
ÌìĞş:[36m²»´í[2;37;0m ÇÉÖÆ:[36m²»´í[2;37;0m 
×ÏÊ¯:[36m²»´í[2;37;0m 
ÒÔ¼°Ò»ÅÅ¹Å×­×Ö¡¾ [1;32mÄ½ÈİÈË[2;37;0m ¡¿¡£ºÍÒ»Ğ©¡¾ [1;32mÈ­·¨[2;37;0m ¡¿µÄ¼¼ÇÉ¡£

LONG
);
			set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "ebebeb");
		set("ownername", "Ä½ÈİÈË");
		set("value", 9000);
		set("armor_prop/intelligence",8);
		set("armor_prop/strength",24);
		set("armor_prop/karey",9);
		set("armor_prop/percao",8);
		set("armor_prop/dexerity",8);
		set("armor_prop/constitution",17);
    set("armor_prop/dodge", 24);
    set("armor_prop/parry", 17);
    set("armor_prop/attack", 32);


    set("armor_prop/armor", 626);
    set("armor_prop/defense", 40);
    
    set("armor_prop/neili", 16);
    set("armor_prop/qi", 40);
    set("armor_prop/jing", 32);
    set("armor_prop/jingli", 16);
    set("armor_prop/damage", 104);

    set("wtypeA",1);
    set("wtypeB",2);
    set("wtypeC",2);
    set("wtypeD",1);
    set("wtypeE",1);
    set("wtypeF",2);
    set("wtypeG",3);
    set("wtypeH",5);
    set("wtypeI",3);
    set("wtypeJ",3);
    set("wtypeK",0);
    set("wtypeL",8);
    
    
                set("skill", ([
                        "name": "cuff",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 240,              
                ]) );		


		set("material", "default");
    set("sharpness", 10);
        }
        setup();
}

int query_autoload() { return 1; }

#include "/obj/armorzy.h";