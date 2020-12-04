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
	      set_name("[1;32mÌìÌìÖ®·ş[2;37;0m", ({ "lianyu cloth", "cloth" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "¼ş");
		set("long", @LONG
[1;31mÈıÊ®ÈıÌìÏÂÓĞµØ£¬µØÏÂÓĞ³Ç£¬³ÇÃû¹í³Ç£¬´óĞ¡ÑıÄ§£¬ÈËÉñĞóÉú¶¼ÔÚ´ËÂÖ»ØÍù·µ£¬Î½Ö®¡°Á¶Óü¡±£¡
[2;37;0mÕâÊÇÒ»¼şÓÉÎŞ±È¼áÓ²µÄ[37mĞşÌú[2;37;0m¼ÓÉÏ[1;37m±ù²ÏË¿[2;37;0mÖÆ³É£¬ÖØÆß½ïÆßÁ½ËÄÇ®µÄ[1;31mÁ¶ÓüÖ®·ş×°[2;37;0m¡£
×ÛºÏÆÀ¼Û[1;36mÎŞË«ÎŞ¶Ô[2;37;0m ¿´ÆğÀ´ÎŞ±È¼á¹Ì£¬¾ßÓĞ[31mÎŞÓëÂ×±È[2;37;0mµÄ·À»¤Á¦£¡
ÉÏÃæ¿ÌÁË¼¸¸ö¹Å·ûºÅ£º
[36mÄ¾[2;37;0m:[35m±ê×¼[2;37;0m [31m»ğ[2;37;0m:[1;34m¾ÙÊÀ[2;37;0m [33mÍÁ[2;37;0m:[1;33mÌìÊ¥[2;37;0m [1;35m·ç[2;37;0m:[1;34m¾ÙÊÀ[2;37;0m 
[1;37mÀ×[2;37;0m:[1;36mÍêÃÀ[2;37;0m 
ÉÏÃæ»¹¿ÌÁËÒ»Ğ©·û×Ö£º
¼áÓ²:[1;31m»ÙÌì[2;37;0m ÇÉÖÆ:[34mÏ¸Ëé[2;37;0m 
°×Ê¯:[32m´Ö²Ú[2;37;0m ÉÁµç:[32m´Ö²Ú[2;37;0m 
ÖÜÌì:[1;36mÍêÃÀ[2;37;0m ³¤Éú:[32m´Ö²Ú[2;37;0m 
ÒÔ¼°Ò»ÅÅ¹Å×­×Ö¡¾ [1;32mÌìÌìÏòÉÏ[2;37;0m ¡¿¡£ºÍÒ»Ğ©¡¾ [1;32mÕĞ¼Ü[2;37;0m ¡¿µÄ¼¼ÇÉ¡£

LONG
);
			set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "feige");
		set("ownername", "ÌìÌìÏòÉÏ");
		set("value", 25000);
		set("armor_prop/intelligence",0);
		set("armor_prop/strength",32);
		set("armor_prop/karey",0);
		set("armor_prop/percao",56);
		set("armor_prop/dexerity",0);
		set("armor_prop/constitution",0);
    set("armor_prop/dodge", 35);
    set("armor_prop/parry", 0);
    set("armor_prop/attack", 32);


    set("armor_prop/armor", 684);
    set("armor_prop/defense", 32);
    
    set("armor_prop/neili", 74);
    set("armor_prop/qi", 38);
    set("armor_prop/jing", 0);
    set("armor_prop/jingli", 48);
    set("armor_prop/damage", 155);

    set("wtypeA",0);
    set("wtypeB",5);
    set("wtypeC",0);
    set("wtypeD",8);
    set("wtypeE",10);
    set("wtypeF",8);
    set("wtypeG",7);
    set("wtypeH",0);
    set("wtypeI",4);
    set("wtypeJ",0);
    set("wtypeK",6);
    set("wtypeL",0);
    
    
                set("skill", ([
                        "name": "parry",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 300,              
                ]) );		


		set("material", "default");
    set("sharpness", 15);
        }
        setup();
}

int query_autoload() { return 1; }

#include "/obj/armorzy.h";